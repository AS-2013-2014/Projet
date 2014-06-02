#include "../include/debug.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Game.hpp"
#include "../include/Scene.hpp"

Game::Game()
{
}

void Game::setScene(Scene* s)
{
	scene = s;
}

void Game::setWindow(sf::RenderWindow* w)
{
	window = w;
}

int Game::run()
{
	while(window->isOpen())
	{

#ifdef DEBUG
std::cout << "----------------------" << std::endl;
#endif

		sf::Event event;
		while(window->pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window->close();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return 0;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			scene->pauseOnOff();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			scene->setCharacterAction(Character::JUMP);

		window->clear(sf::Color::White);
		scene->update();
		scene->draw(*window);
		window->display();
	}
}
