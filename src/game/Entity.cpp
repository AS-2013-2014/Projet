
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): recupération coordonées                                     */
/*--------------------------------------------------------------------------*/
/* Description:  classe mère de toutes les entitées                         */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

// FIXME: draw

Entity::Entity(sf::Vector2i coord, float z ,int length , int width, float angle){
	this->coord=coord;
	this->z=z;
<<<<<<< HEAD
	this->size=sf::Vector2i(length, width);
	this->angle=angle;
}

Entity::Entity(int x, int y, float z, int length, int width, float angle){
	coord=sf::Vector2i(x,y);
	this->z=z;
	this->size=sf::Vector2i(length, width);
	this->angle=angle;
=======
	rect=sf::RectangleShape(sf::Vector2f(length,width));
	rect.setPosition(sf::Vector2f(coord));
}

Entity::Entity(int x, int y, float z, int length, int width){
	coord=sf::Vector2i(x,y);
	this->z=z;
	rect=sf::RectangleShape(sf::Vector2f(length,width));
	rect.setPosition(sf::Vector2f(coord));
>>>>>>> ae63b3e55f7722250c172a30f20857d06ffb6aac
}
sf::Vector2i Entity::getCoord () const {
	return coord;
}
float Entity::getZ() const{
	return z;
}
int Entity::getX() const{
	return coord.x;
<<<<<<< HEAD
}
int Entity::getY() const{
	return coord.y;
}
int Entity::getLength() const{
	return size::x;
}
int Entity::getWidth() const{
	return rect::y;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;
	
	target.draw(rect, states);
}

=======
}
int Entity::getY() const{
	return coord.y;
}
int Entity::getLength() const{
	return rect.getSize().x;
}
int Entity::getWidth() const{
	return rect.getSize().y;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;
	
	target.draw(rect, states);
}

>>>>>>> ae63b3e55f7722250c172a30f20857d06ffb6aac

