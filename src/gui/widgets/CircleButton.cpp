#include <SFML/Graphics.hpp>
#include "CircleButton.hpp"
#include <iostream>
using namespace std;


void CircleButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
    states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

    // on applique la texture
    states.texture = NULL;
    target.draw(circle, states);
}
//on defini la courleur du cercle ainsi que la couleur de son anneau
 void CircleButton::setColorButton(sf::Color colorCircle, sf::Color colorRing){
        circle.setFillColor(colorCircle);
        circle.setOutlineColor(colorRing);
    }



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
