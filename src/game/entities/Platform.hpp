#ifndef PLATEFORM
#define PLATEFORM


#include "../Segment.hpp"
#include <SFML/Graphics.hpp>
#include "../Entity.hpp"
#include <vector>

class Platform: public Entity {
	public:
	Segment s1;
	Segment s2;
	Segment s3;
	Segment s4;
	int type;
	int skin;
	Platform();
	Platform(int x, int y, float z, int lenght, int width, float angle, int type, int skin);
	Platform(sf::Vector2i coord, float z, int lenght, int width, float angle, int type, int skin);
  std::vector<float> getOtherX();
	bool intersect(Segment s) const;
};

#endif
