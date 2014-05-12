
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s):  récupération vitesse                                       */
/*--------------------------------------------------------------------------*/
/* Description:  classe mère de toutes les entitées pouvant se déplacer     */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#include "LivingEntity.hpp"
#include <SFML/Graphics.hpp>

LivingEntity::LivingEntity(sf::Vector2i coord, float z, int length , int width ,sf::Vector2f movement){
	Entity(coord ,z, length, width);
	this->movement=movement;
}

LivingEntity::LivingEntity(int x, int y, float z, int length , int width ,sf::Vector2f movement){
	Entity(x , y , z, length, width);
	this->movement=movement;
}

sf::Vector2f LivingEntity::getMovement() const {
	return movement;
}
void LivingEntity::move(sf::Vector2f movement){
	this->movement=movement;
	coord+=sf::movement;
	Entity::rect.move(movement);
}
