
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                             */
/*                                                                            */
/*                                                                                            */
/* Categorie: moteur physique                                                    */
/*                                                                          */
/* Fonction(s):                                 */
/*--------------------------------------------------------------------------*/
/* Description:                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef LEVEL
#define LEVEL

#include "Section.hpp"
#include "entities/Platform.hpp"
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define SECTION_WIDTH 300

class Level
{
	public:
	std::vector<Section> sections;
	std::vector<Platform> platforms;// à retirer ?
	int width;
	int nb_sections;
	Level(std::string file);
};

void read_plateform(int tab[], std::string line);
int read_lvl_width(std::string line);

#endif
