#ifndef SCENE_HPP
#define SCENE_HPP

class Platform;
class Character;
class Graphic;

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Character.hpp"

class Scene
{
	protected:
	int width;
	Character character;
	std::vector<Solid> solids;
	std::vector<Graphic> graphics;
	sf::View view;
	sf::Clock clock;
	bool pause;
	float cameraSpeed;

	public:
	Scene(const std::string&);
	Platform readPlatform(const std::string&) const;
	int readLvlWidth(std::string);
	void setCharacterAction(Character::Action);
	void configureCamera(sf::Vector2f, sf::Vector2f, float);
	void setCharacter(Character);
	void addPlatform(Platform);
	void addGraphic(Graphic);
	void update();
	void draw(sf::RenderWindow&) const;
	void pauseOnOff();
	sf::Vector2f getViewPosition() const;
	sf::Time getTime() const;
	void setCameraSpeed(float);
	std::vector<Solid> getSolids() const;
	void moveView(sf::Vector2f);
	void resetViewY();
	enum Action
	{
		BEGIN_PLATFORM_CREATION,
		END_PLATFORM_CREATION
	};
};

#endif
