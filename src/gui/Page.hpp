/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: interface                                                     */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Une page (menu, réglage, crédits, etc)                      */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef H_PAGE
#define H_PAGE
#include <SFML/Graphics.hpp>
#include <vector>
#include "Widget.hpp"
#include "widgets/RectangleButton.hpp"
#include "widgets/CircleButton.hpp"
#include "widgets/Slider.hpp"
using namespace sf;
using namespace std;

class Page
{
private:
  // Attributs


public:
  vector<RectangleButton>   mesRect = vector<RectangleButton>(5);
  vector<CircleButton>     mesCircl = vector<CircleButton>(4);
  vector<Slider>            mesSlid = vector<Slider>(2);
  string cheminImage;

  // Constructeurs
  Page(){}

  Page (vector<RectangleButton> widgets, string chemin)
  {
    mesRect = widgets;
    cheminImage = chemin;
  }

  ~Page()
  {
    /*for(int i=0; i<mesWidgets.size(); ++i)
    {
        delete mesWidgets[i];  //On libère la i-ème case mémoire allouée
        mesWidgets[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }*/
  }

  // Méthodes
  void ajouterWidget (RectangleButton monWidget)
  {
    mesRect.push_back(monWidget);
  }

  void ajouterWidget (CircleButton monWidget)
  {
    mesCircl.push_back(monWidget);
  }

  void ajouterWidget (Slider monWidget)
  {
    mesSlid.push_back(monWidget);
  }

};

#endif
