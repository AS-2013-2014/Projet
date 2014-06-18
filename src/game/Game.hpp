#ifndef H_GAME
#define H_GAME

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "const.hpp"

class Game
{
	private:
	sf::RenderWindow* window;
	Scene scene;

	public:
	Game(sf::RenderWindow& window);
	sf::RenderWindow& getWindow();
	Scene& getScene();
	void frame(float time);
};

#endif
