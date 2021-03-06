#include "Solid.hpp"

Solid::Solid():Entity(0,0,0,0,0,0)
{
}

Solid::Solid(int x, int y, float z, int length, int width, int angle)
	:	Entity(x,y,z,length,width, angle)
{
}

HitBox Solid::getHitBox() const
{
	return hitBox;
}

void Solid::setColor(sf::Color c){
	color = c;
}
