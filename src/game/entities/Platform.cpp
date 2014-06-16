#include "Platform.hpp"
#include <cmath>
#include "../Segment.hpp"
#include <SFML/Graphics.hpp>
#include "../Game.hpp"
#include <vector>

Platform::Platform(int x, int y, float z, int length, int width, float angle, int type, int skin)
	:Entity(x,y,z,length,width,angle)
{
	//les operations de transformations sont effectuées par la scène
	this->rect=sf::RectangleShape(sf::Vector2f(length,width));
	rect.setFillColor(sf::Color(0,0,0));

	sf::Vector2f pt0 = rect.getTransform().transformPoint(rect.getPoint(0));
	sf::Vector2f pt1 = rect.getTransform().transformPoint(rect.getPoint(1));
	sf::Vector2f pt2 = rect.getTransform().transformPoint(rect.getPoint(2));
	sf::Vector2f pt3 = rect.getTransform().transformPoint(rect.getPoint(3));

	Segment(pt0, pt1);
	Segment(pt1, pt2);
	Segment(pt2, pt3);
	Segment(pt3, pt0);
	this->type=type;
	this->skin=skin;
}

Platform::Platform(sf::Vector2f coord, float z, int length, int width, float angle, int type, int skin)
	:Entity(coord,z, length, width,angle)
{
	rect=sf::RectangleShape(sf::Vector2f(length,width));
	rect.setRotation(angle);
	rect.setPosition(sf::Vector2f(coord));

	sf::Vector2f pt0 = rect.getTransform().transformPoint(rect.getPoint(0));
	sf::Vector2f pt1 = rect.getTransform().transformPoint(rect.getPoint(1));
	sf::Vector2f pt2 = rect.getTransform().transformPoint(rect.getPoint(2));
	sf::Vector2f pt3 = rect.getTransform().transformPoint(rect.getPoint(3));

	Segment(pt0, pt1);
	Segment(pt1, pt2);
	Segment(pt2, pt3);
	Segment(pt3, pt0);
	this->type=type;
	this->skin=skin;
}

Platform::Platform():Entity(0,0,0,0,0,0)
{
}

bool Platform::intersect(Segment s) const {
	return s1.intersect(s) || s2.intersect(s) || s3.intersect(s) || s4.intersect(s);
}

std::vector<float> Platform::getOtherX(){
	sf::Vector2f pt1 = rect.getTransform().transformPoint(rect.getPoint(1));
	sf::Vector2f pt2 = rect.getTransform().transformPoint(rect.getPoint(2));
	sf::Vector2f pt3 = rect.getTransform().transformPoint(rect.getPoint(3));

  std::vector<float> others;
	others.push_back(pt1.x);
	others.push_back(pt2.x);
	others.push_back(pt3.x);

	return others;
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = NULL;

	target.draw(rect, states);
}
