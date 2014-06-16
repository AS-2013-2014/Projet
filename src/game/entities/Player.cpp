
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

#include "Player.hpp"
#include <SFML/Graphics.hpp>

Player::Player(sf::Vector2f coord, float z , int length , int width ,float angle, sf::Vector2f movement)
    :LivingEntity(coord, length, width, angle , movement,z)
{
	double_jump = false;
}

Player::Player(int x , int y , float z , int length , int width ,float angle, sf::Vector2f movement)
    :LivingEntity(x , y , length, width, angle , movement, z)
{
	double_jump = false;
}

bool Player::getDoubleJump(){
	return double_jump;
}
void Player::doubleJump(){
	double_jump = true;
}
void Player::landing(){
	double_jump = false;
}

