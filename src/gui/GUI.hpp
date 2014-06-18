/****************************************************************************/
/* DUT INFO AS - Projet AS */
/* */
/* */
/* Categorie: interface */
/* */
/* Fonction(s): */
/*--------------------------------------------------------------------------*/
/* Description: Interface graphique (Graphical User Interface) */
/* */
/* */
/* */
/* */
/****************************************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Page.hpp"
#include "Slider.hpp"

#ifndef H_Gui
#define H_Gui

/** CONVENTION PAGES **/
enum pageCode
{
    HANDINLM = 0,
    PORTAL = 1,
    HOME = 2,
    PLAY = 3,
    WORLDS = 4,
    EARTH = 5,
    WATER = 6,
    AIR = 7,
    FIRE = 8,
    OPTION = 9,
    HELP = 10,
    JUMP = 11,
    CREATEDECK = 12,
    CREDIT = 13
};

class GUI : public sf::Drawable, public sf::Transformable
{
  vector<Page> pageSet;
  Page currentPage;

public:
  //Constructeur qui fait tout
  GUI(sf::RenderWindow &window);
 // redifnition de la méthode draw afin de dessiné le bouton avec son texte respectif
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
