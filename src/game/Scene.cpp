
#include "Scene.hpp"
#include "Game.hpp"

Scene::Scene(Game *_game, const std::string &file): game(_game)
{
    std::ifstream lvl_file(file.c_str(),std::ios::in);

		if(lvl_file)
		{
			//lecture de la longueur du niveau
			std::string line;
			getline(lvl_file,line);
			this->width = readLvlWidth(line);

			//création des sections
			this->nb_sections = (int)ceil(width/SECTION_WIDTH);

			for (int i=0 ; i<nb_sections ; i++)
			{
					sections.push_back(Section());
			}
			std::cout<<nb_sections<<std::endl;

			//création des plateformes
			getline(lvl_file,line);
			Platform p;
			while (line != "END")
			{
					p = readPlateform(line);
					platforms.push_back(p);

					//on ajoute la plateforme aux sections correspondantes
					int section_min = (int)p.getX()/SECTION_WIDTH;
					int section_max = (int)p.getX()/SECTION_WIDTH;
					for (int i=0; i<3; i++)
					{
							if ((int)p.getOtherX()[i]/SECTION_WIDTH < section_min)
									section_min = p.getOtherX()[i];
							else if (p.getOtherX()[i]/SECTION_WIDTH > section_min)
									section_max = p.getOtherX()[i];
					}
					for (int i=section_min; i<=section_max; i++)
					{
							sections[i].platforms.push_back(p);
					}

					//le mettre dans les autres sections ^^

					getline(lvl_file,line);
			}

			//fermer le fichier
			lvl_file.close();
		}

  //chargement du shader
	sh_fade = new sf::Shader;
	if(sf::Shader::isAvailable() && sh_fade->loadFromFile("misc/fade.frag", sf::Shader::Fragment))
    sh_fade->setParameter("texture", sf::Shader::CurrentTexture);
}

Scene::~Scene()
{
	for(int i = 0; i < graphics.size(); i++)
		delete graphics[i];

	delete sh_fade;
}

Platform readPlateform(std::string line)
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

    tmp = "";
    while (line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    float z = atof(tmp.c_str());
    i++;

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

    while (line[i]!=':')
    {
        tmp += line[i];
        i++;
    }
    int skin = atoi(tmp.c_str());

    return Platform(x,y,z,length,width,angle,type,skin);
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
        graphics.push_back(new WImage(x,y,z,w,h,r,"images/"+src));
			}
		}

    std::sort(graphics.begin(), graphics.end(), Graphic::sort);
	}
}

void Scene::frame(float time)
{
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

	for(int i = 0; i < graphics.size(); i++)
	{
		Graphic& gr = *(graphics[i]);

		//calcul pour l'affichage
		float pc = (10.0-(float)gr.z)/10.0;
		float x = ((float)gr.x-cam.x)*pc+view.x/2.0;
		float y = ((float)gr.y-cam.y)*pc+view.y/2.0;
		float a = (10.0-(float)gr.z)/10.0;
		float r = gr.r;

		//parametre du shader
		sh_fade->setParameter("a", a);

		//transformation
		gr.setPosition(x,y);
		gr.setScale(pc,pc);
		gr.setRotation(r);

		target.draw(gr, states);
	}
}



