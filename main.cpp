#include "include/debug.hpp"

#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "include/const.hpp"
#include "include/Game.hpp"
#include "include/Scene.hpp"
#include "include/Segment.hpp"
#include "include/HitBox.hpp"
#include "include/Entity.hpp"
#include "include/Solid.hpp"
#include "include/Platform.hpp"
#include "include/Character.hpp"
#include "include/Graphic.hpp"

// pour générer des plate-formes aléatoires :
#include <cstdlib>
#include <time.h>

// FIXME : utiliser des références dès que possible
// revenir à l'ancien système pour le moteur, et modifier l'accélération/décélération pour que le maximum de différentiel soit rapidement atteint
// peut-être opter pour une progression discrète ?

int main() {

	// icône de fenêtre
	sf::Image icone;
	icone.loadFromFile(ICONE);
	const Uint8 *pixelArray = icone.getPixelsPtr();

	// fenêtre
	sf::ContextSettings settings;
	settings.antialiasingLevel = ANTI_ALIASING;
	sf::RenderWindow window(
		sf::VideoMode(800, 600),
		TITLE,
		sf::Style::Default,
		settings);
	window.setIcon(icone.getSize().x, icone.getSize().y, pixelArray);
	window.setPosition(sf::Vector2i(0, 0));

	// textures
	sf::Texture texturePerso1;
	texturePerso1.loadFromFile(PERSO_CONTENT_TEXTURE_1);
	texturePerso1.setRepeated(true);
	sf::Texture textureGround;
	textureGround.loadFromFile(GROUND_TEXTURE);
	textureGround.setRepeated(true);

	// hitBox du perso
	std::vector<sf::Vector2f> hbPoints;
	hbPoints.push_back(sf::Vector2f(10, 45));
	hbPoints.push_back(sf::Vector2f(10, 5));
	hbPoints.push_back(sf::Vector2f(35, 5));
	hbPoints.push_back(sf::Vector2f(35, 45));
	HitBox hitBoxPerso(hbPoints);

	// scene
	Scene scene("./levels/level1.txt");
	scene.configureCamera(sf::Vector2f(0, 0), sf::Vector2f(800, 600), 1);
	scene.setCameraSpeed(4);

	// ajout du perso
	scene.setCharacter(Character(
		&scene,
		sf::Vector2f(300, 0),
		sf::Vector2f(100, 50),
		0, 0, hitBoxPerso
	));

	Game game;
	game.setScene(&scene);
	game.setWindow(&window);

	while(1)
	{
		if(game.run() == 0)
			return 0;
	}
}
