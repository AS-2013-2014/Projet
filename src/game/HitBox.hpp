#ifndef HITBOX_HPP
#define HITBOX_HPP

#include "debug.hpp"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Segment.hpp"


class HitBox
{
	protected:
	std::vector<Segment> segments;

	public:
	HitBox();
	HitBox(std::vector<sf::Vector2f>);
	bool intersectsWith(Segment s) const;
	std::vector<Segment> getSegments() const;
	void move(sf::Vector2f d);
	void draw(sf::RenderWindow&) const;
};

#endif
