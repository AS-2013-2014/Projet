#ifndef GAME_HPP
#define GAME_HPP

class Scene;

#include <SFML/Graphics.hpp>

class Game
{
	private:
	Scene* scene;
	sf::RenderWindow* window;

	public:
	Game();
	void setScene(Scene*);
	void setWindow(sf::RenderWindow*);
	int run();
};

#endif
