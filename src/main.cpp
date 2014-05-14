
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: main                                                          */
/*                                                                          */
/* Fonction(s):  main                                                       */
/*--------------------------------------------------------------------------*/
/* Description:  main                                                       */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#include <iostream>

//modules
#include "misc/Resources.hpp"
#include "game/Game.hpp"

int main(int argc, char** argv)
{
	//instruction unique pour tout le programme
	//initialise le gestionnaire de ressources
	Resources resources;

	//chargements de ressources de test
	Resources::loadTexture("images/test2.png");
	Resources::loadTexture("images/test.png");

  sf::RenderWindow window(sf::VideoMode(800,600), "Test");
  window.setFramerateLimit(50);
  sf::Clock clock;
  Game game(window);

  while(window.isOpen()){
    sf::Event evt;
    while(window.pollEvent(evt)){
      if(evt.type == sf::Event::Closed)
        window.close();
    }

    float elapsed = clock.restart().asSeconds();

    game.frame(elapsed);

    window.clear();
    window.draw(game.getScene());
    window.display();
  }

	return 0;
}
