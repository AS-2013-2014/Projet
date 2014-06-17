#ifndef RECT_BUTTON
#define RECT_BUTTON

/************************************************************************/
/*                      DUT INFO AS - PROJET AS                         */
/*                                                                      */
/*                                                                      */
/* Categorie: Equipe Interface Utilisateur (GUI)                        */
/*                                                                      */
/* Fonction : Classe Boutton                                            */
/* ------------------------------------------------------------         */
/* Description :                                                        */
/*  Cette classe permet de créer un bouton avec un texte predefini.     */
/*                                                                      */
/*                                                                      */
/*                                                                      */
/************************************************************************/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../Widget.hpp"

class RectangleButton : public sf::Drawable, public sf::Transformable,  public  Widget{

// definition des attributs afin de concevoir le bouton
    sf:: Text text;
    sf::Font font;
    sf::RectangleShape rect;
     int x_;         // abscisse coin en haut à gauche
    int y_;
    int longueur_;
    int largeur_;

public :
    RectangleButton()
    {

    }

    RectangleButton(int _x, int _y, int _width, int _height,  sf::String textB)
    {
        setType(BUTTON_RECT);
        x_=_x;
        y_=_y;
        longueur_=_height;
        largeur_=_width;
        if (!font.loadFromFile("resources/sansation.ttf"))
        {
            std::cout<<"probleme de chargement"<<std::endl;
        }
// Definir la police du  texte ainsi que sa taille
        text.setFont(font);
        text.setString(textB);
        text.setCharacterSize(20);

// Recuperation des informations du texte pour le centrer dans le bouton
        float tt = text.getLocalBounds().width;
        float uu = text.getLocalBounds().height;
        text.setPosition(sf::Vector2f(  (_width/2 - tt/2)  , (_height-uu)/ 2 - (text.getCharacterSize()-uu) ));
        text.setColor(sf::Color::White);

// On defini la taille ainsi que le position du bouton
        rect.setSize(sf::Vector2f(_width, _height));
        setPosition(sf::Vector2f(_x,_y));
        rect.setFillColor(sf::Color::Black);
    }
// procédure qui permet de redéfinir la couleur du bouton
    void setColorButton(sf::Color color);
//Getters
    int getX() const;
    int getY() const;
    int getLongueur() const;
    int getLargeur() const;
//Si    click   sur bouton
  bool estDansButton(int x, int y) const;

// redifnition de la méthode draw afin de dessiné le bouton avec son texte respectif
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};


#endif
