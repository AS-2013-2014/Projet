
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

#ifndef LIVING_ENTITY
#define LIVING_ENTITY

#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

	class LivingEntity: public Entity{

		sf::Vector2f movement

		public:
			LivingEntity (sf::Vector2i coord , float z = 0, int length , int width,float angle  ,sf::Vector2f movement);
			LivingEntity (int x, int y , float z = 0 , int length , int width,float angle  ,sf::Vector2f movement);
			sf::Vector2f getMovement() const;
			void move(sf::Vector2f movement);
	};
#endif
