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
#include "Platform.hpp"

class Player : public Solid
{
	private:
    bool dead;


  //graphiques
	sf::RectangleShape rect;
  sf::Sprite anim;
  sf::Vector2f anim_size;
  int cur_frame;
  float dist_reached;
  void updateAnim(sf::Vector2f d);
  //fin graphiques
    
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
