
#include "Platform.hpp"

Platform::Platform(int x, int y, float z, int length, int width, float angle, int type, int skin)
	:Solid(x,y,z,length,width,angle)
{
	//les operations de transformations sont effectuées par la scène
	sf::RectangleShape rect(sf::Vector2f(length,width));	
	rect.setFillColor(sf::Color(0,0,0));
        rect.setRotation(angle);
    rect.setPosition(sf::Vector2f(x, y));
	
    std::vector<sf::Vector2f> points;
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(0)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(1)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(2)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(3)));
	hitBox = HitBox(points);
	this->type=type;
	this->skin=skin;
}

Platform::Platform(sf::Vector2f coord, float z, int length, int width, float angle, int type, int skin)
	:Solid(coord.x,coord.y,z,length,width,angle)
{
	//les operations de transformations sont effectuées par la scène
	sf::RectangleShape rect(sf::Vector2f(length,width));	
	rect.setFillColor(sf::Color(0,0,0));
    rect.setPosition(coord);
    rect.setRotation(angle);
	
    std::vector<sf::Vector2f> points;
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(0)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(1)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(2)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(3)));
	hitBox = HitBox(points);

	this->type=type;
	this->skin=skin;
}

Platform::Platform():Solid(0,0,0,0,0,0)
{
} 

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.texture = NULL;

  //rendu des plateformes
  sf::Sprite sp = splatform;
  const float& pu = platform_unit;

  //middle
  sp.setTextureRect(sf::IntRect(pu,pu,pu,pu));
  sp.setPosition(0,0);
  while(sp.getPosition().x < size.x-2*pu){
    sf::Vector2f pos = sp.getPosition();
    pos.y = 0;
    sp.setPosition(pos);

    sp.move(pu+skin_margin,0);
    while(sp.getPosition().y < size.y-2*pu){
      sp.move(0,pu+skin_margin);
      target.draw(sp,states);
    }
  }


  //left
  sp.setTextureRect(sf::IntRect(0,pu,pu,pu));
  sp.setPosition(0,0);
  while(sp.getPosition().y < size.y-2*pu){
    sp.move(0,pu+skin_margin);
    target.draw(sp, states);
  }


  //right
  sp.setTextureRect(sf::IntRect(2*pu,pu,pu,pu));
  sp.setPosition(size.x-pu,0);
  while(sp.getPosition().y < size.y-2*pu){
    sp.move(0,pu+skin_margin);
    target.draw(sp, states);
  }

  
  //bot
  sp.setTextureRect(sf::IntRect(pu,2*pu,pu,pu));
  sp.setPosition(0,size.y-pu);
  while(sp.getPosition().x < size.x-2*pu){
    sp.move(pu+skin_margin,0);

    if(sp.getPosition().y >= 0)
      target.draw(sp, states);
  }

  //top
  sp.setTextureRect(sf::IntRect(pu,0,pu,pu));
  sp.setPosition(0,0);
  while(sp.getPosition().x < size.x-2*pu){
    sp.move(pu+skin_margin,0);
    target.draw(sp, states);
  }



  //bot right
  sp.setTextureRect(sf::IntRect(2*pu,2*pu,pu,pu));
  sp.setPosition(size.x-pu,size.y-pu);
  if(sp.getPosition().y >= 0)
    target.draw(sp,states);

  //bot left
  sp.setTextureRect(sf::IntRect(0,2*pu,pu,pu));
  sp.setPosition(0,size.y-pu);
  if(sp.getPosition().y >= 0)
    target.draw(sp,states);



  //top right
  sp.setTextureRect(sf::IntRect(2*pu,0,pu,pu));
  sp.setPosition(size.x-pu,0);
  target.draw(sp,states);


  //top left
  sp.setTextureRect(sf::IntRect(0,0,pu,pu));
  sp.setPosition(0,0);
  target.draw(sp,states);

}

float Platform::skin_margin = -1;

void Platform::setSkin(sf::Sprite& splat, float platu){
  platform_unit = platu;
  splatform = splat;
}

