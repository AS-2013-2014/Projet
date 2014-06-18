#include <SFML/Graphics.hpp>
#include "RectangleButton.hpp"
#include <iostream>
using namespace std;


RectangleButton::RectangleButton(){}
RectangleButton::RectangleButton(int _x, int _y, int _width, int _height, sf::String textB)
{

  x_=_x;
  y_=_y;
  longueur_=_height;
  largeur_=_width;

  if (!font.loadFromFile("resources/sansation.ttf"))
    {
      cout << "probleme de chargement" << endl;
    }
// Definir la police du texte ainsi que sa taille

  text.setFont(font);
  text.setString(textB);
  text.setCharacterSize(20);

// Recuperation des informations du texte pour le centrer dans le bouton
  float tt = text.getLocalBounds().width;
  float uu = text.getLocalBounds().height;

  text.setPosition(sf::Vector2f( (_width/2 - tt/2) , (_height-uu)/ 2 - (text.getCharacterSize()-uu) ));
  text.setColor(sf::Color::Black);


// On defini la taille ainsi que le position du bouton
  rect.setSize(sf::Vector2f(_width, _height));
  setPosition(sf::Vector2f(_x,_y));

  rect.setFillColor(sf::Color::White);

}
void RectangleButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
  states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

  // on applique la texture
  states.texture = NULL;
  target.draw(rect, states);
  target.draw(text, states);
}
void RectangleButton::setColorButton(sf::Color color)
{
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

sf::Text  RectangleButton::getTexte(){
  return  text;
}

/** Fonction qui détermine si le clique a eu lieu dans le Button **/
bool RectangleButton::estDansButton(int x,int y) const
{
  //sf::Event event;
  if(x > x_ && x < (x_ + largeur_)
      && y > y_ && y < (y_ + longueur_)
    )
    return true;
  else
    return false;
}
/** Si bouton rectangulaire marche, utiliser les formes sfml (rectangle, cercle...) **/

