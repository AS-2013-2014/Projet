#include "../include/debug.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Entity.hpp"

Entity::Entity()
{
}

Entity::Entity(sf::Vector2f p, sf::Vector2f d, float z, int s)
	:	position(p),
		dimensions(d),
		z(z),
		skin(s)
{
	rectangle = sf::RectangleShape(dimensions);
	rectangle.setPosition(position);
}

void Entity::draw(sf::RenderWindow& w) const
{
	w.draw(rectangle);
}
