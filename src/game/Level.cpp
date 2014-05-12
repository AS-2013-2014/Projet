
#include "Level.hpp"

Level::Level(std::string file)
{
    std::ifstream lvl_file("lvl1.txt",std::ios::in);

    //lecture de la longueur du niv + sections
    std::string line;
    getline(lvl_file,line);
    this->width = read_lvl_width(line);

    //création des sections
    this->nb_sections = (int)ceil(width/SECTION_WIDTH);

    for (int i=0 ; i<nb_sections ; i++)
    {
        sections.push_back(Section());
    }
    std::cout<<nb_sections<<std::endl;

    //création des plateformes
    int tab_plateform[]={0,0,0,0,0,0,0};
    getline(lvl_file,line);
    while (line != "END")
    {
        read_plateform(tab_plateform,line);

        //ajouter à la liste des plateformes
        //ajouter à la bonne section

        getline(lvl_file,line);
        for (int i=0;i<7;i++)
            tab_plateform[i]=0;
    }

    //fermer le fichier




}


void read_plateform(int tab[], std::string line)
{
	int signe=1;
	int j=0;
	for(int i=0;i<7;i++)
	{
		if (line[j]=='-')
		{
			signe=-1;
			j++;
		}
		while (line[j]!=':')
		{
			tab[i]*=10;
			tab[i]+=(int)(line[j]-'0');
			j++;
		}
	tab[i]*=signe;
	signe=1;
	j++;
	}
}

int read_lvl_width(std::string line)
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

