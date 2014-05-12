
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): récupération et affectation du bool de double jump          */
/*--------------------------------------------------------------------------*/
/* Description:  joueur                                                     */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef PLAYER
#define PLAYER

#include "Player.hpp"
#include "LivingEntity.hpp"
#include <SFML/Graphics.hpp>

	class Player: public LivingEntity {
		bool double_jump;

		public:

		Player(sf::Vector2i coord, float z ,int length , int width , sf::Vector2f movement);
		Player(int x , int y , float z , int length , int width , sf::Vector2f movement);
		bool getDoubleJump();
		void doubleJump();
		void landing();
	};
#endif
