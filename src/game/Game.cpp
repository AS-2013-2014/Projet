
#include "Game.hpp"


const float Game::PI=3.1415;


Game::Game(sf::RenderWindow& _window) : scene(this)
{
	window = &_window;
	scene.loadLevel("base.lvl");
  scene.loadGraphics("base.graph");
}

void Game::frame(float time)
{
  float cam_speed = 200;
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
