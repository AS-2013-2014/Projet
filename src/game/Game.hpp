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
    MUI* mui;
    

	public:
	Game(sf::RenderWindow& window, MUI& mui);
	sf::RenderWindow& getWindow();
	Scene& getScene();
	void frame(float time);
    MUI& getMui() {return mui*;}
    
};

#endif
