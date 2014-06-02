#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Scene;

#include <SFML/Graphics.hpp>
#include "Solid.hpp"
#include <vector>

class Character : public Solid
{
	protected:
	Scene* scene;
	int timer;
	int motion_angle;
	bool jumping;
	bool double_jumping;
	bool jumpCommand;
	bool collided;
	float gapToReference;

	public:
	Character();
	Character(Scene*, sf::Vector2f, sf::Vector2f, float, int, HitBox);
	void move(sf::Vector2f);
	void jump();
	//sf::Vector2f computeTrajectory(int);
	//void testTrajectory(const std::vector<Solid>&, const sf::Vector2f&);
	//int findEscapeAngle(const std::vector<Solid>&);
	void move(const std::vector<Solid>&);
	void move();
	enum Action
	{
		JUMP,
		SWIPE,
		SHOOT,
		SUICIDE,
		TAKEAPOO
	};
};

#endif
