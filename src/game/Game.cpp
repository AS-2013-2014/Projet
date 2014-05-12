
#include "Game.hpp"


const float Game::PI=3.1415;


Game::Game(sf::RenderWindow& _window) : scene("base.lvl")
{
	window = &_window;
}

void Game::frame(float time)
{
	scene.frame(time);
}
