/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): Gestion des collisions                               	    */
/*--------------------------------------------------------------------------*/
/* Description: Les segments font office de hitbox pour gérer             	*/
/* les collisions. Si le segment d'une entité coupe le segment d'une autre, */
/* il y a collision.                                                        */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#include "Segment.hpp"


Segment::Segment()
{
}

Segment::Segment(sf::Vector2f a, sf::Vector2f b)
{
	if(a.x == b.x) {
		vertical = true;
		p1 = (a.y <= b.y) ? a : b;
		p2 = (a.y <= b.y) ? b : a; slope = 0;
		origin = 0;
	}
	else {
		vertical = false;
		p1 = (a.x <= b.x) ? a : b;
		p2 = (a.x <= b.x) ? b : a;
		slope = (p2.y-p1.y)/(p2.x-p1.x);
		origin = p1.y - slope*p1.x;
	}
}

bool Segment::intersectsWith(Segment s) const
{
	if(vertical)
	{
		if(s.isVertical())
		{
			if(s.getP1().x == p1.x)
				return (s.getP1().y >= p1.y && s.getP1().y <= p2.y) || (s.getP2().y >= p1.y && s.getP2().y <= p2.y);
			return false;
		}
		float inter = s.getSlope()*p1.x + s.getOrigin();
		return inter >= p1.y && inter <= p2.y && s.getP1().x <= p1.x && s.getP2().x >= p1.x;
	}
	if(s.isVertical())
	{
		float inter = slope*s.getP1().x + origin;
		return inter >= s.getP1().y && inter <= s.getP2().y && p1.x <= s.getP1().x && p2.x >= s.getP1().x;
	}
	float inter = (s.getOrigin()-origin)/(slope-s.getSlope());
	return inter >= p1.x && inter <= p2.x && inter >= s.getP1().x && inter <= s.getP2().x;
}

void Segment::move(sf::Vector2f d)
{
	p1 += d;
	p2 += d;
}

void Segment::draw(sf::RenderWindow &w) const
{
	sf::Vertex vertices[] = {
		sf::Vertex(p1, sf::Color::Black),
		sf::Vertex(p2, sf::Color::Black)
	};
	w.draw(vertices, 2, sf::Lines);
}

float Segment::getSlope() const
{
	return slope;
}

float Segment::getOrigin() const
{
	return origin;
}

sf::Vector2f Segment::getP1() const
{
	return p1;
}

sf::Vector2f Segment::getP2() const
{
	return p2;
}

bool Segment::isVertical() const
{
	return vertical;
}
