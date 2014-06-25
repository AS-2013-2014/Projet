#include <SFML/Graphics.hpp>
#include "CircleButton.hpp"
#include <iostream>
using namespace std;


 //...Constructeur de Notre circleButton
    CircleButton::CircleButton(int _x, int _y, int _dimension, sf::Color colorCircle, sf::Color colorRing)
    {

        // On defini la taille , la couleur ainsi que le position du bouton
        circle.setRadius(_dimension);
        setPosition(sf::Vector2f(_x,_y));
        circle.setFillColor(colorCircle);

// on defini la largeur de l'anneau
        circle.setOutlineThickness(0.3*_dimension);
        circle.setOutlineColor(colorRing);

    }

//...m�thode draw  permettant de dessiner notre rectangleButton
void CircleButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    //...on applique la transformation de l'entit� -- on la combine avec celle qui a �t� pass�e par l'appelant...
    states.transform *= getTransform(); // getTransform() est d�finie par sf::Transformable

    //...on applique la texture...
    states.texture = NULL;
    target.draw(circle, states);
}


//...m�thode setColorButton defini la couleur du cercle ainsi que la couleur de son anneau...
 void CircleButton::setColorButton(sf::Color colorCircle, sf::Color colorRing){
    circle.setFillColor(colorCircle);
    circle.setOutlineColor(colorRing);
}


/*
int main()
{

    CircleButton b1( 300, 300, 120 ,sf::Color::Blue, sf::Color::Cyan);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                {window.close();}
        }

        window.draw(b1);
        window.display();
    }


}
*/
