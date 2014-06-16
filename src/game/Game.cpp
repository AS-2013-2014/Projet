
#include "Game.hpp"


const float Game::PI=3.1415;


Game::Game(sf::RenderWindow& _window) : scene(this)
{
	window = &_window;
<<<<<<< HEAD
	scene.loadLevel("level1.lvl");
        scene.loadGraphics("base.graph");
=======
	scene.loadLevel("levels/level1.txt");
  scene.loadGraphics("base.graph");
>>>>>>> 1f043b111c2dcc735d30de9f48925d170627e946
}

void Game::frame(float time)
{
	float cam_speed = 300;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		scene.getCam().x -= time*cam_speed;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		scene.getCam().x += time*cam_speed;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		scene.getCam().y -= time*cam_speed;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		scene.getCam().y += time*cam_speed;


	scene.frame(time);
}
