#ifndef PLATFORM_HPP
#define PLATFORM_HPP

class Texture;

#include "Solid.hpp"
#include <SFML/Graphics.hpp>

class Platform : public Solid
{
	protected:
	int angle;
	int type;

	public:
	Platform();
	Platform(sf::Vector2f, sf::Vector2f, int, int);
};

#endif
