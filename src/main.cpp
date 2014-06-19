#include <iostream>

// modules
#include "misc/Resources.hpp"
#include "game/Game.hpp"
#include "game/Segment.hpp"
#include <SFML/Graphics.hpp>
#include "gui/GUI.hpp"

#include "mui/MUI.hpp"

int main(int argc, char** argv)
{
	// instruction unique pour tout le programme
	// initialise le gestionnaire de ressources
	Resources resources;

	// chargement de ressources de test
	Resources::loadTexture("images/fond.jpg");
	Resources::loadTexture("images/anim-player.png");
  Resources::loadFont("misc/arial.ttf");
  Resources::loadTexture("images/anim-aura.png");
  Resources::loadTexture("images/anim-fire.png");
  Resources::loadTexture("images/anim-fire2.png");
  Resources::loadTexture("images/anim-fire3.png");
  Resources::loadTexture("images/anim-fireball.png");
  Resources::loadTexture("images/anim-green.png");
  Resources::loadTexture("images/anim-player.png");
  Resources::loadTexture("images/anim-purpleball.png");
  Resources::loadTexture("images/anim-shield.png");
  Resources::loadTexture("images/anim-strike.png");
  Resources::loadTexture("images/anim-stroke.png");
  Resources::loadTexture("images/anim-violet.png");
  Resources::loadTexture("images/eau-extra1.png");
  Resources::loadTexture("images/eau-extra2.png");
  Resources::loadTexture("images/eau-extra3.png");
  Resources::loadTexture("images/eau-extra4.png");
  Resources::loadTexture("images/eau-go1.png");
  Resources::loadTexture("images/eau-go2.png");
  Resources::loadTexture("images/eau-plat.png");
  Resources::loadTexture("images/eau-po1.png");
  Resources::loadTexture("images/eau-po2.png");
  Resources::loadTexture("images/fond.jpg");
  Resources::loadTexture("images/terre-bg.jpg");
  Resources::loadTexture("images/terre-extra1.png");
  Resources::loadTexture("images/terre-extra2.png");
  Resources::loadTexture("images/terre-extra3.png");
  Resources::loadTexture("images/terre-go1.png");
  Resources::loadTexture("images/terre-go2.png");
  Resources::loadTexture("images/terre-plat.png");
  Resources::loadTexture("images/terre-po1.png");
  Resources::loadTexture("images/terre-po2.png");
  Resources::loadTexture("images/test-bg.jpg");
  Resources::loadTexture("images/test-go1.png");
  Resources::loadTexture("images/test-go2.png");
  Resources::loadTexture("images/test-perso.png");
  Resources::loadTexture("images/test-po1.png");
  Resources::loadTexture("images/test-po2.png");
  Resources::loadTexture("images/test.png");
  Resources::loadTexture("images/test2.png");
    // fenêtre
	sf::RenderWindow window(sf::VideoMode(800,600), "Test");

	// framerate
	window.setFramerateLimit(50);

	// horloge globale (sert à récupérer l'intervalle entre chaque frame)
	sf::Clock clock;

  //init MUI
  MUI mui(800,600);
	// nouveau jeu
	Game game(window, mui);
 
  //init GUI
  GUI gui(window, &game);
  clock.restart();

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
