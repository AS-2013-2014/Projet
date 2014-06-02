#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity
{
	protected:
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	sf::Vector2f dimensions;
	sf::Texture* texture;
	float z;
	int skin;

	public:
	Entity();
	Entity(sf::Vector2f, sf::Vector2f, float, int);
	void draw(sf::RenderWindow&) const;
};

#endif
