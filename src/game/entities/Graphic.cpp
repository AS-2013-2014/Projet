
#include "Graphic.hpp"

Graphic::Graphic(int x, int y, float z, int w, int h, int r):Entity(x,y,z,w,h,r)
{
}

void Graphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;

	sf::RectangleShape rect(sf::Vector2f(size.x, size.y));
	rect.setFillColor(sf::Color(255,255,255));
	
	target.draw(rect, states);
}
