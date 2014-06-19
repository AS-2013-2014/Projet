#include "Entity.hpp"
#include <SFML/Graphics.hpp>

Entity::Entity(sf::Vector2f coord, float z ,int length , int width, float angle)
{
	this->coord = coord;
	this->z = z;
	this->size = sf::Vector2f(length, width);
	this->angle = angle;
  setEType(NONE);
}

Entity::Entity(int x, int y, float z, int length, int width, float angle)
{
	coord = sf::Vector2f(x,y);
	this->z = z;
	this->size = sf::Vector2f(length, width);
	this->angle = angle;
  setEType(NONE);
}

sf::Vector2f Entity::getCoord() const
{
	return coord;
}

float Entity::getZ() const
{
	return z;
}

int Entity::getX() const
{
	return coord.x;
}

int Entity::getY() const
{
	return coord.y;
}

int Entity::getLength() const
{
	return size.x;
}

int Entity::getWidth() const
{
	return size.y;
}

float Entity::getAngle() const
{
	return angle;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;

  sf::RectangleShape r(sf::Vector2f(size.x, size.y));
  r.setFillColor(sf::Color(255, 0, 0));

  target.draw(r, states);
}
