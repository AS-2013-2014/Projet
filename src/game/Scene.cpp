
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
}

Scene::~Scene()
{
	for(int i = 0; i < entities.size(); i++)
		delete entities[i];

	for(int i = 0; i < sections.size(); i++)
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
		while (line.find("END") == std::string::npos)
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
	//on ajoute la plateforme aux entitées du niveau
	entities.push_back(p);

	//on ajoute la plateforme aux sections correspondantes
	int section_min = (int)p->getX()/SECTION_WIDTH;
	int section_max = (int)p->getX()/SECTION_WIDTH;

	for (int i=0; i<3; i++)
	{
			if ((int)p->getOtherX()[i]/SECTION_WIDTH < section_min)
					section_min = p->getOtherX()[i];

			else if (p->getOtherX()[i]/SECTION_WIDTH > section_min)
					section_max = p->getOtherX()[i];
	}
	
	for (int i=section_min; i<=section_max; i++)
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

		/*
    tmp = "";
    while (line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    float z = atof(tmp.c_str());
    i++;
		*/
		//pas de z dans la convention
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

		/*
    while (line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
		*/
		//int skin = atoi(tmp.c_str());
		//changement au niveau de la convention du niveau
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

void Scene::setBackground(const std::string file){
  sf::Texture* tex = Resources::getTexture(file);
  if(tex != NULL)
    background.setTexture(*tex);
}

bool Scene::loadGraphics(const std::string& file)
{
	std::ifstream graph_file(file.c_str());
	if(graph_file)
	{
		//fichier ouvert
		std::string line;
		std::stringstream sline;
    std::stringstream ss;
    int sbuff = 256;
    char buff[sbuff];
			

    //lecture de la ligne d'en tête, le chargement du fond
    if(getline(graph_file, line)){
      sline.str(line);
      sline.getline(buff,sbuff,';'); 
      sline.getline(buff,sbuff,';'); 
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

		
			sline.getline(buff, sbuff, ';');
			ss.clear();
			ss.str(buff);
			ss >> x;

			sline.getline(buff, sbuff, ';');
			ss.clear();
			ss.str(buff);
			ss >> y;

			sline.getline(buff, sbuff, ';');
			ss.clear();
			ss.str(buff);
			ss >> z;

			sline.getline(buff, sbuff, ';');
			ss.clear();
			ss.str(buff);
			ss >> w;

			sline.getline(buff, sbuff, ';');
			ss.clear();
			ss.str(buff);
			ss >> h;

			sline.getline(buff, sbuff, ';');
			ss.clear();
			ss.str(buff);
			ss >> r;

			sline.getline(buff, sbuff, ';');
			ss.clear();
			ss.str(buff);
			ss >> type;

			sline.getline(buff, sbuff, ';');
			ss.clear();
			ss.str(buff);
			ss >> src;

			if(type == "I")
			{
        entities.push_back(new WImage(x,y,z,w,h,r,"images/"+src));
			}
			else if(type == "A")
			{
				int wc,hc;
				float fps;

				sline.getline(buff, sbuff, ';');
				ss.clear();
				ss.str(buff);
				ss >> wc;

				sline.getline(buff, sbuff, ';');
				ss.clear();
				ss.str(buff);
				ss >> hc;

				sline.getline(buff, sbuff, ';');
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
	for(int i = 0; i < entities.size(); i++)
		entities[i]->frame(time);
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



