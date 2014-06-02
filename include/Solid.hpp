#ifndef PHYSICAL_HPP
#define PHYSICAL_HPP

#include "Entity.hpp"
#include "HitBox.hpp"

class Solid : public Entity
{
	protected:
	HitBox hitBox;

	public:
	Solid();
	Solid(sf::Vector2f,	sf::Vector2f, float, int);
	HitBox getHitBox() const;
	void draw(sf::RenderWindow&) const;
};

#endif
