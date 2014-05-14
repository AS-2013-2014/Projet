
#include "Graphic.hpp"

Graphic::Graphic(int _x, int _y, float _z, int _w, int _h, int _r):x(_x),y(_y),z(_z),w(_w),h(_h),r(_r)
{
}

void Graphic::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;

	sf::RectangleShape rect(sf::Vector2f(w,h));
	rect.setFillColor(sf::Color(255,255,255));
	rect.setOrigin(w/2, h/2);
	
	target.draw(rect, states);
}
