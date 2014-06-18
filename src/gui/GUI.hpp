/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: interface                                                     */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Interface graphique (Graphical User Interface)              */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Page.hpp"
#include "Widget.hpp"

#ifndef H_Gui
#define H_Gui

/** CONVENTION PAGES **/
enum pageCode
{
    HANDINLM   = 0,
    PORTAL     = 1,
    HOME       = 2,
    PLAY       = 3,
    WORLDS     = 4,
    EARTH      = 5,
    WATER      = 6,
    AIR        = 7,
    FIRE       = 8,
    OPTION     = 9,
    HELP       = 10,
    JUMP       = 11,
    CREATEDECK = 12,
    CREDIT     = 13
};

class Gui
{
  vector<Page> pageSet = vector<Page>(15);
  Page currentPage;

public:
  //Constructeur qui fait tout
  Gui(sf::RenderWindow &window);
};

#endif
