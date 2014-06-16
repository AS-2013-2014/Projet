#ifndef PHYSICAL_HPP
#define PHYSICAL_HPP

#include "Entity.hpp"
#include "HitBox.hpp"
#include "debug.hpp"
#include <iostream>

class Solid : public Entity
{
	protected:
	HitBox hitBox;
//  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
	Solid();
  Solid(int x, int y, float z, int length, int width, int angle);
	HitBox getHitBox() const;
};

#endif
