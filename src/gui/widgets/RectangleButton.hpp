#ifndef BUTTON
#define BUTTON

/************************************************************************/
/*                      DUT INFO AS - PROJET AS                         */
/*                                                                      */
/*                                                                      */
/* Categorie: Equipe Interface Utilisateur (GUI)                        */
/*                                                                      */
/* Fonction : Classe RectangleBoutton                                            */
/* ------------------------------------------------------------         */
/* Description :                                                        */
/*  Cette classe permet de créer un bouton rectangulaire                */
/*  avec un texte predefini.                                            */
/*                                                                      */
/*                                                                      */
/************************************************************************/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


class RectangleButton : public sf::Drawable, public sf::Transformable {

// definition des attributs afin de concevoir le bouton
    sf:: Text text;
    sf::Font font;
    sf::RectangleShape rect;

public :
    RectangleButton(int _x, int _y, int _width, int _height,  sf::String textB)
    {

        if (!font.loadFromFile("arial.ttf"))
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

// redifnition de la méthode draw afin de dessiné le bouton avec son texte respectif
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
