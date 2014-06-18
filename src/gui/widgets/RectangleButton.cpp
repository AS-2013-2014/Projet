#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
using namespace std;

// methode permettant l'affichage à l'ecran
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
/*
int main()
{

    RectangleButton b1( 150, 80, 400, 50,"TEST BUTTON");

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    // sf::Color color = sf::Color(190,190,190,255);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                {window.close();}

                    if(event.mouseButton.x > 150 && event.mouseButton.x < 550 && event.mouseButton.y > 80 && event.mouseButton.y < 130)
                    {
                        cout<<"Blue"<<endl;
                        cout<<event.mouseMove.x << " - " << event.mouseMove.y <<endl;
                        b1.setColorBushape.setOutlineThickness(10);
shape.setOutlineColor(sf::Color(250, 150, 100));tton(sf::Color(105,105,105,20));

                    }
                    else{  b1.setColorButton(sf::Color::White);}

        }
        sf::Texture texture;
        window.clear(sf::Color::White);
        window.draw(b1);
        window.display();
    }


}
*/
