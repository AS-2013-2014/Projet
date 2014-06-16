
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

LivingEntity::LivingEntity(sf::Vector2f coord, int length, int width, float angle, sf::Vector2f movement, float z)
	:Entity(coord, z, length, width, angle)
{
	this->movement=movement;
}

LivingEntity::LivingEntity(int x, int y, int length, int width, float angle, sf::Vector2f movement, float z)
: Entity(x, y, z, length, width, angle)
{
	this->movement=movement;
}

sf::Vector2f LivingEntity::getMovement() const {
	return movement;
}
void LivingEntity::move(sf::Vector2f movement){
	this->movement=movement;
	coord+=movement;
	//Entity::rect.move(movement);
}
