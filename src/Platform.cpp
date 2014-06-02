#include "../include/debug.hpp"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/HitBox.hpp"
#include "../include/Entity.hpp"
#include "../include/Platform.hpp"

Platform::Platform()
{
}

Platform::Platform(sf::Vector2f p, sf::Vector2f d, int a, int t)
	:	Solid(p, d, 0, 0),
		angle(a),
		type(t)
{
	rectangle.setRotation(a);
	std::vector<sf::Vector2f> points;
	points.push_back(rectangle.getTransform().transformPoint(rectangle.getPoint(0)));
	points.push_back(rectangle.getTransform().transformPoint(rectangle.getPoint(1)));
	points.push_back(rectangle.getTransform().transformPoint(rectangle.getPoint(2)));
	points.push_back(rectangle.getTransform().transformPoint(rectangle.getPoint(3)));
	hitBox = HitBox(points);
}
