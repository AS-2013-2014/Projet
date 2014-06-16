
#include "Platform.hpp"

Platform::Platform(int x, int y, float z, int length, int width, float angle, int type, int skin)
	:Solid(x,y,z,length,width,angle)
{
	//les operations de transformations sont effectuées par la scène
	sf::RectangleShape rect(sf::Vector2f(length,width));	
	rect.setFillColor(sf::Color(0,0,0));
        rect.setRotation(angle);
	
  std::vector<sf::Vector2f> points;
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(0)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(1)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(2)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(3)));
	hitBox = HitBox(points);

	this->type=type;
	this->skin=skin;
}

Platform::Platform(sf::Vector2f coord, float z, int length, int width, float angle, int type, int skin)
	:Solid(coord.x,coord.y,z,length,width,angle)
{
	//les operations de transformations sont effectuées par la scène
	sf::RectangleShape rect(sf::Vector2f(length,width));	
	rect.setFillColor(sf::Color(0,0,0));
  rect.setRotation(angle);
	
  std::vector<sf::Vector2f> points;
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(0)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(1)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(2)));
	points.push_back(rect.getTransform().transformPoint(rect.getPoint(3)));
	hitBox = HitBox(points);

	this->type=type;
	this->skin=skin;
}

Platform::Platform():Solid(0,0,0,0,0,0)
{
} void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.texture = NULL;

  sf::RectangleShape rect(sf::Vector2f(size.x, size.y));
  rect.setFillColor(sf::Color(0,255,0));
  target.draw(rect, states);
}
