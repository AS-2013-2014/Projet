
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

Entity::Entity(sf::Vector2i coord, float z ,int length , int width){
	this->coord=coord;
	this->z=z;
	rect=sf::RectangleShape(sf::Vector2f(length,width));
	rect.setPosition(sf::Vector2f(coord));
}

Entity::Entity(int x, int y, float z, int length, int width){
	coord=sf::Vector2i(x,y);
	this->z=z;
	rect=sf::RectangleShape(sf::Vector2f(length,width));
	rect.setPosition(sf::Vector2f(coord));
}
sf::Vector2i Entity::getCoord () const {
	return coord;
}
float Entity::getZ() const{
	return z;
}
int Entity::getX() const{
	return coord.x;
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
