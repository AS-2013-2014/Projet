/************************************************************************/
/*                      DUT INFO AS - PROJET AS                         */
/*                                                                      */
/*                                                                      */
/* Categorie: Equipe Interface Utilisateur (GUI)                        */
/*                                                                      */
/* Fonction : Classe CircleButton                                       */
/* ------------------------------------------------------------         */
/* Description :                                                        */
/*  Cette classe permet de créer un bouton circulaire avec un anneau de */
/*   couleur differentes.                                               */
/*                                                                      */
/*                                                                      */
/************************************************************************/
#ifndef CIRCLE_BUTTON
#define CIRCLE_BUTTON
#include <SFML/Graphics.hpp>


class CircleButton : public sf::Drawable, public sf::Transformable {

//...definition des attributs afin de concevoir le bouton...
    sf::CircleShape circle;
    sf::Texture texture;

public :
    //...Constructeur...
    CircleButton(int _x, int _y, int _dimension, sf::Color colorCircle, sf::Color colorRing);

    //...procédure qui permet de redéfinir les couleur du circleButton...
    void setColorButton(sf::Color colorCircle, sf::Color colorRing);

    //...redifnition de la méthode draw afin de dessiné le circleButton...
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
