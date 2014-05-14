
#include "WImage.hpp"

WImage::WImage(int x, int y, float z, int w, int h, int r, const std::string& file):Graphic(x,y,z,w,h,r)
{
	sf::Texture *tex = Resources::getTexture(file);
	sprite.setTexture(*tex);

	if(tex != NULL){
		float sx = w/(float)tex->getSize().x;
		float sy = h/(float)tex->getSize().y;
		sprite.setScale(sx,sy);
		sprite.setOrigin(tex->getSize().x/2.0, tex->getSize().y/2.0);
	}

}

void WImage::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;

	target.draw(sprite, states);
}
