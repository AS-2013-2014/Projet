
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

#ifndef SCENE
#define SCENE

#include "Section.hpp"
#include "entities/Platform.hpp"
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h> // atof, atoi
#include <SFML/Graphics.hpp>

#define SECTION_WIDTH 300

class Scene : public sf::Drawable, public sf::Transformable
{
	public:
	std::vector<Section> sections;
	std::vector<Platform> platforms;
	int width;
	int nb_sections;
	Scene(const std::string &file);

	void frame(float time);

	private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

Platform readPlateform(std::string line);
int readLvlWidth(std::string line);

#endif
