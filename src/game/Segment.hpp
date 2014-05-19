/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): Gestion des collisions                               	    */
/*--------------------------------------------------------------------------*/
/* Description: Les segments font office de hitbox pour gérer               */
/* les collisions. Si le segment d'une entité coupe le segment d'une autre, */
/* il y a collision.                                                        */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef SEGMENT
#define SEGMENT

#include <SFML/Graphics.hpp>

class Segment {

	private:
	sf::Vector2f p1;
	sf::Vector2f p2;
	bool vertical;
	float slope;
	float origin;

	public:
	float getSlope() const;
	float getOrigin() const;
	sf::Vector2f getP1() const;
	sf::Vector2f getP2() const;
	bool isVertical() const;
	Segment(); // pourquoi ? demander à Robin/Nico
	Segment(sf::Vector2f a, sf::Vector2f b);
	bool intersect(Segment s) const;
	void draw(sf::RenderWindow &w) const;
};

#endif
