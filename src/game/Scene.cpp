#include "Scene.hpp"

//inclusion reflexive, ne pas retirer ni rajouter dans le .hpp
#include "Game.hpp"


Scene::Scene(Game *_game): game(_game)
{
	this->width = 0;
	this->nb_sections = 0;

	//chargement du shader
	sh_fade = new sf::Shader;
	if(sf::Shader::isAvailable() && sh_fade->loadFromFile("misc/fade.frag", sf::Shader::Fragment))

		sh_fade->setParameter("texture", sf::Shader::CurrentTexture);

  setPlatformSkin("images/platform_test.png");
}

void Scene::addPlayer() {
	//creation du joueur

	// hitBox du perso
	std::vector<sf::Vector2f> hbPoints;
	hbPoints.push_back(sf::Vector2f(10, 45));
	hbPoints.push_back(sf::Vector2f(10, 5));
	hbPoints.push_back(sf::Vector2f(35, 5));
	hbPoints.push_back(sf::Vector2f(35, 45));
	HitBox hitBoxPerso(hbPoints);

	// ajout du perso

	setPlayer(new Player(
		this,
		sf::Vector2f(300, 0),
		sf::Vector2f(100, 50),
		0, 0, hitBoxPerso
	));


	entities.push_back(character);

}

Scene::~Scene()
{

	for(int i = entities.size()-1; i >= 0; i--)
		delete entities[i];

	for(int i = sections.size()-1; i >= 0; i--)
		delete sections[i];

	delete sh_fade;
}

void Scene::loadLevel(const std::string &file)
{
	std::ifstream lvl_file(file.c_str(),std::ios::in);
	
	if(lvl_file)
	{
		//lecture de la longueur du niveau
		std::string line;
		getline(lvl_file,line);
		this->width = readLvlWidth(line);

		//création des sections pour la gestion des collisions
		this->nb_sections = (int)ceil(width/SECTION_WIDTH);


		for (int i=0 ; i<nb_sections ; i++)
		{
				sections.push_back(new Section());
		}

		//création des plateformes
		getline(lvl_file,line);
		Platform* p;


		while(line.find("END") == std::string::npos)

		{				
				p = readPlatform(line);
				addPlatform(p);

				getline(lvl_file,line);
		}

		//fermeture du fichier
		lvl_file.close();
	}
}

void Scene::addPlatform(Platform* p) 
{
  p->setSkin(splatform, platform_unit);

	//on ajoute la plateforme aux entitées du niveau
	entities.push_back(p);
    solids.push_back(p);

	// on ajoute la plateforme aux sections correspondantes
	int section_min = (int)p->getX();
	int section_max = (int)p->getX();

	std::vector<Segment> segs = p->getHitBox().getSegments();
	for(int i=0; i < segs.size(); i++)
	{
		if(segs[i].getP1().x < section_min)
				section_min = segs[i].getP1().x;
		else if(segs[i].getP1().x > section_max)
				section_max = segs[i].getP1().x;
		if (segs[i].getP2().x < section_min)
				section_min = segs[i].getP2().x;
		else if (segs[i].getP2().x > section_max)
				section_max = segs[i].getP2().x;
	}
	
	for (int i=section_min/SECTION_WIDTH; i<=section_max/SECTION_WIDTH; i++)
	{
		if(i >= 0 && i < sections.size())
			sections[i]->platforms.push_back(p);
	}
}

Platform* readPlatform(std::string line)
{
	int i = 0;

	std::string tmp = "";
	while (line[i]!=':')

	{
		tmp += line[i];
		i++;
	}
	int x = atoi(tmp.c_str());
	i++;

	tmp = "";
	while (line[i]!=':')
	{
		tmp += line[i];
		i++;
	}
	int y = atoi(tmp.c_str());
	i++;

	float z = 0;

	tmp = "";
	while (line[i]!=':')
	{
		tmp += line[i];
		i++;
	}
	int length = atoi(tmp.c_str());
	i++;

	tmp = "";
	while (line[i]!=':')
	{
		tmp += line[i];
		i++;
	}
	int width = atoi(tmp.c_str());
	i++;

	tmp = "";
	while (line[i]!=':')
	{
		tmp += line[i];
		i++;
	}
	int angle = atoi(tmp.c_str());
	i++;

	while (line[i]!=':')
	{
		tmp += line[i];
		i++;
	}
	int type = atoi(tmp.c_str());
	i++;

	int skin = 0;

	return new Platform(x,y,z,length,width,angle,type,skin);

}

int readLvlWidth(std::string line)
{
	int width = 0;
	int i = 0;
	while (line[i]!=':')
	{
		width *= 10;
		width += (int)(line[i]-'0');
		i++;
	}
	return width;
}

void Scene::setBackground(const std::string file)
{
	sf::Texture* tex = Resources::getTexture(file);
	if(tex != NULL)
		background.setTexture(*tex);
}

void Scene::loadGraphics(const std::string& file)
{
	std::ifstream graph_file(file.c_str());
	if(graph_file)
	{
		//fichier ouvert
		std::string line;
		std::stringstream sline;

		std::stringstream ss;
		
		char buff[SBUFF];
			

		//lecture de la ligne d'en tête, le chargement du fond
		if(getline(graph_file, line)) {
			sline.str(line);
			sline.getline(buff,SBUFF,';');
			sline.getline(buff,SBUFF,';');
			setBackground("images/"+std::string(buff));
		}


		//lecture de chaque ligne
		while(getline(graph_file, line))
		{
			sline.clear();
			sline.str(line);

			//extraction des informations
			int x, y, w, h, r;
			float z;
			std::string type, src;

		
			sline.getline(buff, SBUFF, ';');
			ss.clear();
			ss.str(buff);
			ss >> x;

			sline.getline(buff, SBUFF, ';');
			ss.clear();
			ss.str(buff);
			ss >> y;

			sline.getline(buff, SBUFF, ';');
			ss.clear();
			ss.str(buff);
			ss >> z;

			sline.getline(buff, SBUFF, ';');
			ss.clear();
			ss.str(buff);
			ss >> w;

			sline.getline(buff, SBUFF, ';');
			ss.clear();
			ss.str(buff);
			ss >> h;

			sline.getline(buff, SBUFF, ';');
			ss.clear();
			ss.str(buff);
			ss >> r;

			sline.getline(buff, SBUFF, ';');
			ss.clear();
			ss.str(buff);
			ss >> type;

			sline.getline(buff, SBUFF, ';');
			ss.clear();
			ss.str(buff);
			ss >> src;

			if(type == "I")

				entities.push_back(new WImage(x,y,z,w,h,r,"images/"+src));

			else if(type == "A")
			{
				int wc,hc;
				float fps;

				sline.getline(buff, SBUFF, ';');
				ss.clear();
				ss.str(buff);
				ss >> wc;

				sline.getline(buff, SBUFF, ';');
				ss.clear();
				ss.str(buff);
				ss >> hc;

				sline.getline(buff, SBUFF, ';');
				ss.clear();
				ss.str(buff);
				ss >> fps;

				WAnimation* an = new WAnimation(x,y,z,w,h,r,"images/"+src,wc,hc,fps);
				an->play();

				entities.push_back(an);
			}
		}
		std::sort(entities.begin(), entities.end(), Entity::sort);

	}
}

void Scene::frame(float time)
{

	cam.x += time*SPEED*50;


	for(int i = 0; i < entities.size(); i++)
		entities[i]->frame(time);


	//character->move();

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = NULL;

	sf::Vector2f view = game->getWindow().getView().getSize();

	//fond
	target.draw(background, states);

	//utilisation du shader
	if(background.getTexture() != NULL){
		states.shader = sh_fade;
		sh_fade->setParameter("background", *background.getTexture());
		sh_fade->setParameter("width", game->getWindow().getSize().x);
		sh_fade->setParameter("height", game->getWindow().getSize().y);
	}

	for(int i = 0; i < entities.size(); i++)
	{
		Entity& e = *(entities[i]);

		//calcul pour l'affichage
		float pc = (10.0-(float)e.getZ())/10.0;
		float x = ((float)e.getX()-cam.x)*pc+view.x/2.0;
		float y = ((float)e.getY()-cam.y)*pc+view.y/2.0;
		float a = (10.0-(float)e.getZ())/10.0;
		float r = e.getAngle();

		//parametre du shader
		sh_fade->setParameter("a", a);

		//transformation
		e.setPosition(x,y);
		e.setScale(pc,pc);
		e.setRotation(r);


		target.draw(e, states);
	}
}


void Scene::setPlatformSkin(const std::string& src){
  sf::Texture* tex = Resources::getTexture(src);
  if(tex != NULL){
    splatform.setTexture(*tex);
    const sf::Vector2u& size = tex->getSize();
    platform_unit = (size.x > size.y ? size.y : size.x) / 3.0;
  }
  else
    platform_unit = 1000;
}

void Scene::setPlayerAction(Player::Action a)
{
	switch(a)
	{
		case Player::JUMP :
			character->jump();
			break;
	}

}

void Scene::setPlayer(Player* c)
{
	character = c;
}

