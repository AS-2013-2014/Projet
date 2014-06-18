#include <iostream>

// modules
#include "misc/Resources.hpp"
#include "game/Game.hpp"
#include "game/Segment.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
	// instruction unique pour tout le programme
	// initialise le gestionnaire de ressources
	Resources resources;

	// chargement de ressources de test
	Resources::loadTexture("images/test2.png");
	Resources::loadTexture("images/test.png");
	Resources::loadTexture("images/fond.jpg");
	Resources::loadTexture("images/fire.png");
	Resources::loadTexture("images/aura.png");
	Resources::loadTexture("images/platform_test.png");

	// fenêtre
	sf::RenderWindow window(sf::VideoMode(800,600), "Test");

	// framerate
	window.setFramerateLimit(50);

	// horloge globale (sert à récupérer l'intervalle entre chaque frame)
	sf::Clock clock;

	// nouveau jeu
	Game game(window);
	game.load(1,1);
	game.setPlay(true);

	// boucle principale
	while(window.isOpen())
	{
		// boucle d'évènements
		sf::Event evt;
		while(window.pollEvent(evt))
		{
			if(evt.type == sf::Event::Closed)
				window.close();
			else if (evt.type == sf::Event::KeyPressed) {
				if (evt.key.code == sf::Keyboard::P) {
					game.setPlay(!game.getPlay());
				}
			}
				
		}

		// temps écoulé depuis la dernière frame
		float elapsed = clock.restart().asSeconds();

		// transmission du temps écoulé au jeu
		game.frame(elapsed);

		// séquence de refresh
		window.clear();
		window.draw(game.getScene());
		window.display();
	}

	return 0;
}
