#ifndef RECT_BUTTON
#define RECT_BUTTON

/************************************************************************/
/* DUT INFO AS - PROJET AS */
/* */
/* */
/* Categorie: Equipe Interface Utilisateur (GUI) */
/* */
/* Fonction : Classe Boutton */
/* ------------------------------------------------------------ */
/* Description : */
/* Cette classe permet de créer un bouton avec un texte predefini. */
/* */
/* */
/* */
/************************************************************************/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Resources.hpp"

class RectangleButton : public sf::Drawable, public sf::Transformable{

// definition des attributs afin de concevoir le bouton
    sf::Text text;
    sf::Font font;
    sf::RectangleShape rect;
     int x_; // abscisse coin en haut à gauche
    int y_;
    int longueur_;
    int largeur_;

public :
    RectangleButton();

    RectangleButton(int _x, int _y, int _width, int _height, sf::String textB);

// procédure qui permet de redéfinir la couleur du bouton
    void setColorButton(sf::Color color);
//Getters
    int getX() const;
    int getY() const;
    int getLongueur() const;
    int getLargeur() const;
//Si click sur bouton
  bool estDansButton(int x, int y) const;

  std::string getTexte() const;

// redifnition de la méthode draw afin de dessiné le bouton avec son texte respectif
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};


#endif
