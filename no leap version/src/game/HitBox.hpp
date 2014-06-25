#ifndef HITBOX_HPP
#define HITBOX_HPP

#include "debug.hpp"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Segment.hpp"


class HitBox:public sf::Transformable,public sf::Drawable
{
	protected:
	std::vector<Segment> segments;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f coord;

	public:
	HitBox();
	HitBox(std::vector<sf::Vector2f>);
	bool intersectsWith(Segment s) const;
	std::vector<Segment> getSegments() const;
	sf::Vector2f getPos() const;
	void move(sf::Vector2f d);
	void draw(sf::RenderTarget&) const;
};

#endif
