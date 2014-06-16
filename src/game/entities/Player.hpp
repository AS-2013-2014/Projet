/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): récupération et affectation du bool de double jump          */
/*--------------------------------------------------------------------------*/
/* Description:  joueur                                                     */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

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
	protected:
	sf::RectangleShape rect;
	Scene* scene;
	int timer;
	int motion_angle;
	bool jumping;
	bool double_jumping;
	bool jumpCommand;
	bool collided;
	float gapToReference;

	public:
	Player();
	Player(Scene*, sf::Vector2f, sf::Vector2f, float, int, HitBox);
	void move(sf::Vector2f);
	void jump();
	//sf::Vector2f computeTrajectory(int);
	//void testTrajectory(const std::vector<Solid>&, const sf::Vector2f&);
	//int findEscapeAngle(const std::vector<Solid>&);
	void move(const std::vector<Solid*>&);
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
