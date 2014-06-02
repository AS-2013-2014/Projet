#include "../include/debug.hpp"
#include <iostream>
#include "../include/HitBox.hpp"
#include "../include/Solid.hpp"

Solid::Solid()
{
}

Solid::Solid(sf::Vector2f p, sf::Vector2f d, float z, int s)
	:	Entity(p, d, z, s)
{
}

HitBox Solid::getHitBox() const
{
	return hitBox;
}

void Solid::draw(sf::RenderWindow& w) const
{
	Entity::draw(w);

#ifdef DEBUG
	hitBox.draw(w);
#endif

}
