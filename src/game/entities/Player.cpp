#include "Player.hpp"
#include "../Scene.hpp"

Player::Player()
{
}

void Player::isDead()
{
    float viewAbs = (scene->getCam()).x; 
    if (coord.x<viewAbs-400-DEAD_MARGIN_X)
        dead=true;
    else if(coord.y>DEAD_MARGIN_Y+scene->getHeight())
        dead=true;
}

Player::Player(Scene* sc, sf::Vector2f p, sf::Vector2f d, float z, int s, HitBox hb)
	:	Solid(p.x, p.y, z, d.x, d.y, 0),
		scene(sc),
		timer(0),
		motion_angle(-90),
		jumping(false),
		double_jumping(false),
		jumpCommand(false),
		collided(false),
		gapToReference(0)
{
	hitBox = hb;
	hitBox.move(p);
}

void Player::move(sf::Vector2f d)
{
    coord += sf::Vector2f(d);
    rect.move(d);
    hitBox.move(d);
    float viewOrd = (scene->getCam()).y;
    if(coord.y < viewOrd - 150) {
		scene->setCam(scene->getCam()+(sf::Vector2f(0, (d.y < 0)?d.y:0)));
	}
    else if(coord.y > viewOrd+200)
    {
		if(viewOrd < scene->getHeight()-100) // TEST ME
			scene->setCam(scene->getCam()+(sf::Vector2f(0, (d.y > 0)?d.y:0)));
		else
			scene->setCam(sf::Vector2f(scene->getCam().x, 300));
    }
    isDead();
}

void Player::jump()
{
	jumpCommand = true;
}

void Player::move(const std::vector<Platform*>& solids)
{

	gapToReference = coord.x - (REF_X*800 + (scene->getCam().x-400));

	float rad = motion_angle*PI_ENGINE/180;
	float dx = 0;
	float dy = 0;

	// déplacement normal
	if(motion_angle >= -MAX_MOVE_ANGLE)
	{
		if(motion_angle <= MAX_MOVE_ANGLE)
		{
			dx = SPEED * (1-sin(rad)*std::abs(sin(rad))) * (1-tanh(gapToReference/50)/2);
			dy = GRAVITY * timer - 20;
		}
		if(motion_angle <= 90)
		{
			if(!jumping && jumpCommand)	
			{
				if(timer > 20)
					double_jumping = true;
				jumping = true;
				timer = 1;
			}
		}
	}

	// chute libre
	else if(motion_angle < MAX_MOVE_ANGLE && motion_angle >= MAX_MOVE_ANGLE-180)
	{
		dx = SPEED * cos(rad);
		dy = GRAVITY * timer;
	}

	// mode saut
	if(jumping)
	{
		dx = SPEED * (1-sin(rad)*std::abs(sin(rad)));
		dy = GRAVITY * timer - 23;
		if(dy >= -DBLE_JUMP_SENSIBILITY && dy <= DBLE_JUMP_SENSIBILITY && !double_jumping && timer >= 1.20)
		{
			if(jumpCommand)
			{
				double_jumping = true;	
				timer = 1;
			}
		}
		if(motion_angle == 90 && double_jumping) dx = SPEED;
	}

	float x1 = coord.x;
	float y1 = coord.y;

	float x2 = x1 + dx;
	float y2 = y1 + dy;

	float d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	int sub_pts = (int)round(d) - 1;

	std::vector<sf::Vector2f> sub_positions;
	sub_positions.push_back(sf::Vector2f(0, 0));
	for(int p = 1; p <= sub_pts; p++)
		sub_positions.push_back(sf::Vector2f(p*(x2-x1)/(sub_pts+1), p*(y2-y1)/(sub_pts+1)));
	sub_positions.push_back(sf::Vector2f(x2-x1, y2-y1));

	bool collisionDetected = false;

	for(int cur_pos = 1; cur_pos < sub_positions.size() && !collisionDetected; cur_pos++)
	{
		for(int i = 0; i < solids.size() && !collisionDetected; i++)
		{
			for(int j = 0; j < hitBox.getSegments().size() && !collisionDetected; j++)
			{
				Segment new_segm(
					hitBox.getSegments()[j].getP1() + sub_positions[cur_pos],
					hitBox.getSegments()[j].getP2() + sub_positions[cur_pos]
				);
				if((solids[i]->getHitBox()).intersectsWith(new_segm))
				{
         
                    			if(solids[i]->getType()==Platform::DEADLY)
                				dead=true;


		                    	collisionDetected = true;
					jumping = false;
					double_jumping = false;
					timer = 1;
					move(sub_positions[cur_pos-1]);

					int angle = -90;
					float angle_rad;
					int pas = 1;
					bool possible = false;
					sf::Vector2f vect;
					float module = 2;

					while(!possible)
					{
						if(angle > MAX_MOVE_ANGLE)
						{
							angle = -91;
							pas = -1;
						}
						else if(angle < MAX_MOVE_ANGLE-180)
							break;
						angle_rad = angle*PI_ENGINE/180;
						possible = true;

						vect = sf::Vector2f(module*cos(angle_rad), -module*sin(angle_rad));
						for(int j = 0; (j < hitBox.getSegments().size()) && possible; j++)
						{
							Segment new_segm(
								hitBox.getSegments()[j].getP1() + vect,
								hitBox.getSegments()[j].getP2() + vect
							);
							for(int e = 0; e < solids.size(); e++)
								possible = possible && !(*(solids[e])).getHitBox().intersectsWith(new_segm);
						}
						angle += pas;
					}
					angle -= pas;
					if(!possible)
						motion_angle = 90;
					else
						motion_angle = angle;


				}
			}
		}
	}
	if(!collisionDetected)
	{
		move(sub_positions.back());
		timer += clockTime;
	}
	collided = collisionDetected;
	jumpCommand = false;
}

void Player::move()
{
	int section1 = (hitBox.getSegments()[0]).getP1().x/SECTION_WIDTH;
	int section2 = (hitBox.getSegments()[2]).getP1().x/SECTION_WIDTH;
	
	std::vector<Solid*> platforms = std::vector<Solid*>();

	if(section1 != section2) {
		platforms.reserve((scene->getSections())[section1]->platforms.size() +  (scene->getSections())[section2]->platforms.size());
		platforms.insert(platforms.end(), (scene->getSections())[section1]->platforms.begin(), (scene->getSections())[section1]->platforms.end());
		platforms.insert(platforms.end(), (scene->getSections())[section2]->platforms.begin(), (scene->getSections())[section2]->platforms.end());
		move(platforms);
	}
	else
		move((scene->getSections())[section1]->platforms);
}

void Player::frame(float time)
{
	clockTime = time;
	move();
}
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = NULL;

	sf::RectangleShape rect(sf::Vector2f(size.x, size.y));
	rect.setFillColor(sf::Color(0, 255, 0));
	target.draw(rect, states);
	states.transform.translate(-(hitBox.getPos()));
	target.draw(hitBox, states);
}
