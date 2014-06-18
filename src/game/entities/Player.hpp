#ifndef PLAYER_H
#define PLAYER_H

class Scene;

#include "../debug.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../const.hpp"
#include "../Segment.hpp"
#include "../HitBox.hpp"
#include "../Solid.hpp"

class Player : public Solid
{
	private:
    bool dead;
	sf::RectangleShape rect;
	Scene* scene;
	float timer;
	int motion_angle;
	bool jumping;
	bool double_jumping;
	bool jumpCommand;
	bool collided;
	float gapToReference;
	float clockTime;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void isDead();

	public:
    bool getDead() const { return dead; } 
	Player();
	Player(Scene*, sf::Vector2f, sf::Vector2f, float, int, HitBox);
	void move(sf::Vector2f);
	void jump();
	void move(const std::vector<Solid*>&);
	void move();
	void frame(float);
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
