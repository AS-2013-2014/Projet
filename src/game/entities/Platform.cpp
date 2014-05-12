#include "Platform.hpp"
#include <cmath>
#include "../Segment.hpp"
#include <SFML/Graphics.hpp>
#include "../Game.hpp"
#include <vector>

Platform::Platform(int x, int y, float z, int length, int width, float angle, int type, int skin)
	:Entity(x,y,z,length,width)
{
	Entity::rect.setRotation(angle);
	Entity::rect.setPosistion(sf::Vector2f(x,y))
	sf::Vector2f pt0 = rect.getTransform().transformPoint(Entity::rect.getPoint(0));
	sf::Vector2f pt1 = rect.getTransform().transformPoint(Entity::rect.getPoint(1));
	sf::Vector2f pt2 = rect.getTransform().transformPoint(Entity::rect.getPoint(2));
	sf::Vector2f pt3 = rect.getTransform().transformPoint(Entity::rect.getPoint(3));
	Segment(pt0, pt1);
	Segment(pt1, pt2);
	Segment(pt2, pt3);
	Segment(pt3, pt0);
	this->type=type;
	this->skin=skin;
}
Platform::Platform(sf::Vector2i coord, float z, int lenght, int width, float angle, int type, int skin)
	:Entity(coord,z)
{
	Entity::rect.setRotation(angle);
	Entity::rect.setPosistion(coord)
	sf::Vector2f pt0 = rect.getTransform().transformPoint(Entity::rect.getPoint(0));
	sf::Vector2f pt1 = rect.getTransform().transformPoint(Entity::rect.getPoint(1));
	sf::Vector2f pt2 = rect.getTransform().transformPoint(Entity::rect.getPoint(2));
	sf::Vector2f pt3 = rect.getTransform().transformPoint(Entity::rect.getPoint(3));
	Segment(pt0, pt1);
	Segment(pt1, pt2);
	Segment(pt2, pt3);
	Segment(pt3, pt0);
	this->type=type;
	this->skin=skin;
}
Platform::Platform(){};
bool Platform::intersect(Segment s) const {
	return s1.intersect(s) || s2.intersect(s) || s3.intersect(s) || s4.intersect(s);
}

vector<float> Platform::getOtherX(){
	sf::Vector2f pt1 = Entity::rect.getTransform().transformPoint(Entity::rect.getPoint(1));
	sf::Vector2f pt2 = Entity::rect.getTransform().transformPoint(Entity::rect.getPoint(2));
	sf::Vector2f pt3 = Entity::rect.getTransform().transformPoint(Entity::rect.getPoint(3));
	vector<float> ohters;
	others.push_back(pt1.x);
	others.push_back(pt2.x);
	others.push_back(pt3.x);
}
