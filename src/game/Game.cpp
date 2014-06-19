#include "Game.hpp"

// constructeur
Game::Game(sf::RenderWindow& _window, MUI& _mui)
	:	 mui(&_mui), scene(this)
{
	window = &_window;
	loadData();
	
  mui->setMode(MUI::MODE_JUMP);
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
	if (play) {
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
			scene.getPlayer()->jump();

		scene.frame(time);
	}
}


void Game::loadData()
{
	std::ifstream file ("save.data");
	
	if (file)
		file>>dataVolume>>dataUnlockedWorld>>dataUnlockedLevel;	
	else
		dataVolume=100, dataUnlockedWorld=1, dataUnlockedLevel=1;
	
	std::cout << "fichier lu " << dataVolume << std::endl;
}


void Game::saveData()
{
	std::ofstream file ("save.data", std::ios::trunc);
	
	if (file)
		file<<dataVolume<<dataUnlockedWorld<<dataUnlockedLevel;	
	
	std::cout << "fichier save " << dataVolume << std::endl;
}


void Game::load(int world, int level)
{
	std::stringstream ss;
	ss << world;
	std::string w = ss.str();
	
	ss.clear();
	ss.str("");
	
	ss << level;
	std::string l = ss.str();
	
	scene.clear();
	scene.loadLevel("levels/level_" + w + "_" + l + ".txt");
	scene.addPlayer();
	scene.loadGraphics("levels/level_" + w + "_" + l + ".graph");
	
}

void Game::setPlay(bool playing)
{
	play = playing;
}



