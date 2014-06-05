
/****************************************************************************/
/* DUT INFO AS - Projet AS */
/* */
/* */
/* Categorie: game */
/* */
/* Fonction(s): */
/*--------------------------------------------------------------------------*/
/* Description: Le jeu en lui même */
/* */
/* */
/* */
/* */
/****************************************************************************/

#ifndef H_GAME
#define H_GAME

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "const.hpp"

class Game
{
  public:
		Game(sf::RenderWindow& window);

		sf::RenderWindow& getWindow(){ return *window; }
		Scene& getScene(){ return scene; }

		void frame(float time);

  private:
		sf::RenderWindow* window;
		Scene scene;
};

#endif
