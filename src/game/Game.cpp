#include "Game.hpp"

// constructeur
Game::Game(sf::RenderWindow& _window)
	:	scene(this)
{
	window = &_window;
	scene.addPlayer();
	scene.loadGraphics("base.graph");
	scene.loadLevel("levels/level1.txt");
}

// retourne une référence vers la fenêtre
sf::RenderWindow& Game::getWindow()
{
	return *window;
}

// retourne une référence vers la scène
Scene& Game::getScene()
{
	return scene;
}

// transmet le temps écoulé à la scène
void Game::frame(float time)
{
	float cam_speed = 300;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		scene.getCam().x -= time*cam_speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		scene.getCam().x += time*cam_speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		scene.getCam().y -= time*cam_speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		scene.getCam().y += time*cam_speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		scene.getPlayer().jump();

	scene.frame(time);
}
