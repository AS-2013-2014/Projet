#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <SFML/Graphics.hpp>

class Segment
{
	protected:
	sf::Vector2f p1;
	sf::Vector2f p2;
	bool vertical;
	float slope;
	float origin;

	public:
	Segment();
	Segment(sf::Vector2f a, sf::Vector2f b);
	bool intersectsWith(Segment) const;
	void move(sf::Vector2f);
	void draw(sf::RenderWindow &) const;
	float getSlope() const;
	float getOrigin() const;
	sf::Vector2f getP1() const;
	sf::Vector2f getP2() const;
	bool isVertical() const;
};

#endif
