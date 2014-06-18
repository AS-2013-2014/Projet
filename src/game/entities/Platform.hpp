#ifndef PLATEFORM
#define PLATEFORM

#include "../Segment.hpp"
#include <SFML/Graphics.hpp>
#include "../Solid.hpp"
#include <vector>
#include <cmath>

class Platform: public Solid {
	private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  sf::Sprite splatform;
  float platform_unit;

	public:
	Segment s1;
	Segment s2;
	Segment s3;
	Segment s4;
	int type;
	int skin;
	Platform();
	Platform(int x, int y, float z, int lenght, int width, float angle, int type, int skin);
	Platform(sf::Vector2f coord, float z, int lenght, int width, float angle, int type, int skin);

  void setSkin(sf::Sprite& splat, float platu);

  static float skin_margin;
};

#endif


