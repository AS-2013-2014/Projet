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
#include "Page.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include  "Widget.hpp"

#ifndef H_GUI
#define H_GUI

class GUI
{
  std::vector<Page>    pageSet;
  Page currentPage;

public:
  //Constructeur  qui fait  tout
  GUI(sf::RenderWindow  &window);
};

#endif
