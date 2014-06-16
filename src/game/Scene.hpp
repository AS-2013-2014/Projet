
/****************************************************************************/
/*											 DUT INFO AS - Projet AS														 */
/*																																						*/
/*																																														*/
/* Categorie: moteur physique																										*/
/*																																					*/
/* Fonction(s):																 */
/*--------------------------------------------------------------------------*/
/* Description:													*/
/*																																					*/
/*																																					*/
/*																																					*/
/*																																					*/
/****************************************************************************/

#ifndef SCENE
#define SCENE

#include "Section.hpp"
#include "entities/Platform.hpp"
#include "Entity.hpp"
#include "entities/WImage.hpp"
#include "entities/WAnimation.hpp"
#include "entities/Player.hpp"
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
	std::vector<Section*> sections;
	std::vector<Entity*> entities;

	Scene(Game *game);
	~Scene();


	void loadGraphics(const std::string& file);

	void setBackground(const std::string file);
	void frame(float time);
	void loadLevel(const std::string &file); // charge le fichier txt du level
	void addPlatform(Platform* p);

	void addPlayer();

	//accesseurs
	sf::Vector2f& getCam(){ return cam; }
	void setCam(const sf::Vector2f& v){ cam = v; }

	std::vector<Solid*>& getSolids(){ return solids; }
	void setPlayerAction(Player::Action);
	void setPlayer(Player*);

	enum Action
	{
		BEGIN_PLATFORM_CREATION,
		END_PLATFORM_CREATION
	};
	

	private:
		Player* character;

	int width;
	int nb_sections;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<Graphic*> graphics;

	std::vector<Solid*> solids;

	sf::Vector2f cam;

	Game *game;
	sf::Sprite background;
	sf::Shader* sh_fade;
};

Platform* readPlatform(std::string line);
int readLvlWidth(std::string line);

#endif
