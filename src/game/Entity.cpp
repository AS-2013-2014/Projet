
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
	rect=sf::RectangleShape(sf::vector2f(length,width));
	rect.setPosition(coord);
}
Entity::Entity(int x, int y, int z){
	coord=sf::Vector2i(x,y);
	this->z=z;
	rect=sf::RectangleShape(sf::vector2f(length,width));
	rect.setPosition(coord);
}
sf::Vector2f Entity::getCoord () const {
	return coord;
}
float Entity::getZ(){
	return z;
}
int Entity::getX(){
	return x;
}
int Entity::getY(){
	return y;
}
int Entity::getLength(){
	return rect.getSize().x;
}
int Entity::getWidth(){
	return rect.getSize().y;
}
