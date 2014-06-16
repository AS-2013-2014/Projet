#include "HitBox.hpp"

HitBox::HitBox()
{
}

HitBox::HitBox(std::vector<sf::Vector2f> points)
{
	for(int p = 0; p < points.size()-1; p++)
		segments.push_back(Segment(points[p], points[p+1]));
	segments.push_back(Segment(points[points.size()-1], points[0]));
}

bool HitBox::intersectsWith(Segment sg) const
{
	for(int s = 0; s < segments.size(); s++)
		if(segments[s].intersectsWith(sg))
			return true;
	return false;
}

std::vector<Segment> HitBox::getSegments() const
{
	return segments;
}

void HitBox::move(sf::Vector2f d)
{
	for(int s = 0; s < segments.size(); s++)
		segments[s].move(d);
}

void HitBox::draw(sf::RenderWindow &w) const
{
	for(int s = 0; s < segments.size(); s++)
		segments[s].draw(w);
}
