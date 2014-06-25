/****************************************************************************/
/* DUT INFO AS - Projet AS */
/* */
/* */
/* Categorie: interface */
/* */
/* Fonction(s): */
/*--------------------------------------------------------------------------*/
/* Description: Une page (menu, réglage, crédits, etc) */
/* */
/* */
/* */
/* */
/****************************************************************************/

#ifndef H_PAGE
#define H_PAGE
#include <SFML/Graphics.hpp>
#include "CircleButton.hpp"
#include "RectangleButton.hpp"
#include "Slider.hpp"
#include <vector>
using namespace sf;
using namespace std;

class Page : public sf::Drawable, public sf::Transformable
{
private:
  // Attributs


public:
  vector<RectangleButton> mesRect;
  vector<CircleButton> mesCircl;
  vector<Slider> mesSlide;
  string cheminImage;

  // Constructeurs
  Page() {

  mesRect= vector<RectangleButton>(6);
//  mesCircl = vector<CircleButton>(4);
//  mesSlid= vector<Slider>(1);
  }

Page (vector<RectangleButton> widgets, vector<Slider> slide)
  {
    mesRect = widgets;
   mesSlide = slide;
  }

  Page (vector<RectangleButton> widgets, string chemin)
  {
    mesRect = widgets;
    cheminImage = chemin;
  }

  ~Page()
  {
    /*for(int i=0; i<mesWidgets.size(); ++i)
    {
    delete mesWidgets[i]; //On libère la i-ème case mémoire allouée
    mesWidgets[i] = 0; //On met le pointeur à 0 pour éviter les soucis
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

/*  void ajouterWidget (Slider monWidget)
  {
    mesSlid.push_back(monWidget);
  }*/

 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif
