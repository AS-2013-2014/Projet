
#include "WAnimation.hpp"

WAnimation::WAnimation(int x, int y, float z, int w, int h, int r, const std::string& file, int _wc, int _hc, float _fps, bool _loop):Graphic(x,y,z,w,h,r),wc(_wc),hc(_hc),fps(_fps),loop(_loop),playing(false),current(0)
{
	sf::Texture *tex = Resources::getTexture(file);

  //calcul de transformation pour la texture
	if(tex != NULL)
	{
    sprite.setTexture(*tex);

    if(wc != 0 && hc != 0)
		{
      size.x = tex->getSize().x/wc; 
      size.y = tex->getSize().y/hc;
    }

    float sx = 1, sy = 1;
    if(w > 0)
      sx = w/size.x;
    if(h > 0)
      sy = h/size.y;

    sprite.scale(sx, sy);
	}

  //calcul du temps d'une frame de l'animation en secondes
  frame_time = 1/(float)fps;
}

void WAnimation::play()
{
  elapsed = 0;
  current = 0;
  playing = true;

  int x = current%wc;
  int y = current/wc;
  sprite.setTextureRect(sf::IntRect(x*size.x, y*size.y, size.x, size.y));
}

void WAnimation::stop()
{
  playing = false;
}

void WAnimation::frame(float time)
{
  if(playing)
	{
    elapsed += time;

    if(elapsed >= frame_time)
		{
      int n = elapsed/frame_time;
      elapsed -= n*frame_time;

      //do n frames
      current += n;

      if(loop)
        current %= wc*hc;
      else if(current >= wc*hc)
        stop();

      //set sprite rect
      int x = current%wc;
      int y = current/wc;
      sprite.setTextureRect(sf::IntRect(x*size.x, y*size.y, size.x, size.y));
    }
  }
}

void WAnimation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;

	if(playing)
		target.draw(sprite, states);
}
