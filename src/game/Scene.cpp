
#include "Scene.hpp"

Scene::Scene(const std::string &file)
{
    std::ifstream lvl_file(file.c_str(),std::ios::in);

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

