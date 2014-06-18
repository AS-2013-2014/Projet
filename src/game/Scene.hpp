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
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#define SECTION_WIDTH 300

// parent pointer
class Game;

class Scene : public sf::Drawable, public sf::Transformable
{
	private:
	Game *game;
	std::vector<Entity*> entities;
	std::vector<Section*> sections;
	std::vector<Graphic*> graphics;
	std::vector<Solid*> solids;
	Player* character;
	sf::Sprite background;
	sf::Shader* sh_fade;
	int width;
	int nb_sections;
	sf::Vector2f cam;

	public:
	Scene(Game *game);
	~Scene();

	static Platform* readPlatform(std::string line);
	static int readLvlWidth(std::string line);
	void loadGraphics(const std::string& file);
	void setBackground(const std::string file);
	void frame(float time);
	void loadLevel(const std::string &file);
	void addPlatform(Platform* p);
	void addPlayer();

	// accesseurs
	sf::Vector2f& getCam() { return cam; }
	void setCam(const sf::Vector2f& v) { cam = v; }
	std::vector<Solid*>& getSolids() { return solids; }
	void setPlayerAction(Player::Action);
	void setPlayer(Player*);
	Player& getPlayer();

	sf::RenderWindow& getWindow();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	enum Action
	{
		BEGIN_PLATFORM_CREATION,
		END_PLATFORM_CREATION
	};
};

#endif
