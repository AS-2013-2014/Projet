
#include "WImage.hpp"

WImage::WImage(int x, int y, float z, int w, int h, int r, const std::string& file):Graphic(x,y,z,w,h,r)
{
	sf::Texture *tex = Resources::getTexture(file);

	if(tex != NULL){
    sprite.setTexture(*tex);
		float sx = w/(float)tex->getSize().x;
		float sy = h/(float)tex->getSize().y;
		sprite.setScale(sx,sy);
	}
}

void WImage::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;

	target.draw(sprite, states);
}
