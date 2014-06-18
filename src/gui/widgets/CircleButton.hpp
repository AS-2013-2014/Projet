/************************************************************************/
/*                      DUT INFO AS - PROJET AS                         */
/*                                                                      */
/*                                                                      */
/* Categorie: Equipe Interface Utilisateur (GUI)                        */
/*                                                                      */
/* Fonction : Classe CircleButton                                       */
/* ------------------------------------------------------------         */
/* Description :                                                        */
/*  Cette classe permet de cr�er un bouton circulaire avec un anneau de */
/*   couleur differentes.                                               */
/*                                                                      */
/*                                                                      */
/************************************************************************/
#ifndef CIRCLE_BUTTON
#define CIRCLE_BUTTON
#include <SFML/Graphics.hpp>

/*  Classe : CircleButton
/*  Parametre du contructeur : - Sa position ( x, y ), son Rayon
/*
/*
/*
/*
/*
/**/


class CircleButton : public sf::Drawable, public sf::Transformable {

// definition des attributs afin de concevoir le bouton
    sf::CircleShape circle;
    sf::Texture texture;

public :
    CircleButton(int _x, int _y, int _dimension, sf::Color colorCircle, sf::Color colorRing)
    {

// On defini la taille , la couleur ainsi que le position du bouton
        circle.setRadius(_dimension);
        setPosition(sf::Vector2f(_x,_y));
        circle.setFillColor(colorCircle);

// on defini la largeur de l'anneau
        circle.setOutlineThickness(0.3*_dimension);
        circle.setOutlineColor(colorRing);

    }

// proc�dure qui permet de red�finir les couleur du circleButton
    void setColorButton(sf::Color colorCircle, sf::Color colorRing);

// redifnition de la m�thode draw afin de dessin� le circleButton
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};


#endif
