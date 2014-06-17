#include <SFML/Graphics.hpp>
#include "RectangleButton.hpp"
#include <iostream>
using namespace std;


void RectangleButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
    states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

    // on applique la texture
    states.texture = NULL;
    target.draw(rect, states);
    target.draw(text, states);
}
 void RectangleButton::setColorButton(sf::Color color){
        rect.setFillColor(color);
}


/** Getters **/
int RectangleButton::getX() const
{
    return x_;
}
int RectangleButton::getY() const
{
    return y_;
}
int RectangleButton::getLongueur() const
{
    return longueur_;
}
int RectangleButton::getLargeur() const
{
    return largeur_;
}

/** Fonction qui détermine si le clique a eu lieu dans le Button **/
bool RectangleButton::estDansButton(int x,int y) const
{
    //sf::Event event;
    if(x > x_ && x < (x_ + longueur_)
       && y > y_ && y < (y_ + largeur_)
       )
        return true;
    else
        return false;
}
/** Si bouton rectangulaire marche, utiliser les formes sfml (rectangle, cercle...) **/

