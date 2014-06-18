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

class Segment:public sf::Drawable,public sf::Transformable
{
	protected:
	sf::Vector2f p1;
	sf::Vector2f p2;
	bool vertical;
	float slope;
	float origin;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
	Segment();
	Segment(sf::Vector2f a, sf::Vector2f b);
	bool intersectsWith(Segment) const;
	void move(sf::Vector2f);
	void draw(sf::RenderTarget &) const;
	float getSlope() const;
	float getOrigin() const;
	sf::Vector2f getP1() const;
	sf::Vector2f getP2() const;
	bool isVertical() const;
	void draw(sf::RenderWindow& w);
};



#endif
