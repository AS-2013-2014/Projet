
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
#include "entities/WImage.hpp"
#include "entities/WAnimation.hpp"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h> // atof, atoi
#include <SFML/Graphics.hpp>

#define SECTION_WIDTH 300

//parent pointer
class Game;

class Scene : public sf::Drawable, public sf::Transformable
{
	public:
	std::vector<Section> sections;
	std::vector<Platform> platforms;
	int width;
	int nb_sections;

	Scene(Game *game,const std::string &file);
	~Scene();

	bool loadGraphics(const std::string& file);
  void setBackground(const std::string file);
	void frame(float time);

	//accesseurs
	sf::Vector2f& getCam(){ return cam; }

	private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<Graphic*> graphics;
	sf::Vector2f cam;

	Game *game;
  sf::Sprite background;
  sf::Shader* sh_fade;
};

Platform readPlateform(std::string line);
int readLvlWidth(std::string line);

#endif
