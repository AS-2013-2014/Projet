#include <SFML/Graphics.hpp>
#include "slide.hpp"
#include <iostream>
#include "RectangleButton.hpp"
//#include <SoundSource.hpp>
using namespace std;

void Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
    states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

    // on applique la texture
    states.texture = NULL;
    target.draw(rect, states);
    target.draw(line0, 2, sf::Lines);
    target.draw(line1, 2, sf::Lines);
    target.draw(line2, 2, sf::Lines);
    target.draw(line3, 2, sf::Lines);
    target.draw(line4, 2, sf::Lines);
    target.draw(line5, 2, sf::Lines);
    target.draw(cursor, states);
    target.draw(bPlus, states);
    target.draw(bMoins, states);

}
/*
void Slide::setColorButton(sf::Color color){
        rect.setFillColor(color);
    }*/

// Change la position du curseur
void Slider::setCursorPosition (int val)
{
    cursor.setPosition(sf::Vector2f(val, (_height - 1.5*_height)/2 ));
}

int Slider::getCursorPosition ()
{
    return positionCursor;
}

bool Slider::estDansSlide (int xSouris, int ySouris)
{
    //cout << "on est dans le slide" << endl;
    // Test slide
    // Elargissement de la zone du slide en prenant en compte les coordonnées du bouton plus et du bouton moins
    int xSlide = _x - bPlus.getX();
    int ySlide = _y;
    int widthSlide = _width + abs(bPlus.getX())*2;
    int heightSlide = _height;
    // Test sur les coordonnées
    if (xSouris > xSlide && xSouris < ( xSlide + widthSlide) && ySouris > ySlide && ySouris < (ySlide + heightSlide))
    {
       // cout << "estDansSlide: slide" << endl;
        return true;
    }
    else
    {
        //cout << "estDansSlide: null part" << endl;
        return false;
    }
}

int Slider::ouDansSlide (int xSouris, int ySouris)
{
    xSouris = xSouris - _x;
    ySouris = ySouris - _y;
    if ( bMoins.estDansButton(xSouris, ySouris) )
        return BMOINS;
    else if (bPlus.estDansButton(xSouris, ySouris))
        return BPLUS;
    else
        cout << "ailleurs" << endl;
    return AILLEURS;
}

void Slider::moveCursor (int xSouris, int ySouris)
{

        // On teste si le click est dans le slider
        if ( estDansSlide(xSouris, ySouris))
        {
            cout << "on est dans le slifde FONCTION MOVE CURSOR" << endl;
            // On regarde où dans le slider
            // Si la souris est dans le bouton plus
            if (ouDansSlide(xSouris, ySouris) == BPLUS)
            {
                // Si le curseur est entre 0 et inférieur au maximum:
                if(positionCursor >= 0 && positionCursor < _width)
                {
                    positionCursor = positionCursor + ecart;
                    cout << "adaptation position " << positionCursor << endl;
                    setCursorPosition(positionCursor);
                    // Réglage du son
                    // Adaptation de la position du curseur par rapport à 100
                    /*float volume = positionCursor / _width * 100;
                    sf::SoundSource::setVolume	(volume	); */

                }
            }
            else if (ouDansSlide(xSouris, ySouris) == BMOINS)
            {

                cout << "position curseur de base " << positionCursor << endl;
                cout << "ecart " << ecart << endl;

                cout << "on est dans le bouton moins" << endl;
                // Si le curseur est compris entre le maximum et supérieur à 0
                if(positionCursor > 0 && positionCursor <= _width)
                {
                    positionCursor = positionCursor - ecart;
                    cout << "adapation position: " << positionCursor << endl;
                    setCursorPosition(positionCursor);
                }
            }
            else
            {
                cout << "On est pas dans les boutons " << endl;
            }
        }
        else
            cout << "on est pas dans le slide " << endl;
        /*cout << "click x: " << xSouris << endl;
        cout << "click y: " << ySouris << endl;
        // On vérifie que la souris est sur le boutton moins
        if (bMoins.estDansButton(xSouris, ySouris))
        {
            cout << "On a clique sur le moins" << endl;
             // Si le curseur est compris entre le maximum et supérieur à 0
            if(positionCursor > 0 && positionCursor <= x)
                {
                    positionCursor = positionCursor - ecart;
                    cout << "position: " << positionCursor << endl;
                    setCursorPosition(positionCursor);
                }
        }
         // On vérifie que la souris est sur le boutton moins
        if (bPlus.estDansButton(xSouris,  ySouris ))
        {
               cout << "On a clique sur le plus" << endl;
            // Si le curseur est entre 0 et inférieur au maximum
            if(positionCursor >= 0 && positionCursor < x)
                {
                    positionCursor = positionCursor - ecart;
                    cout << "position: " << positionCursor << endl;
                    setCursorPosition(positionCursor);
                }
        } */


}


/*
int main()
{
    // Déclaration des variables et objets
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    Slide b1( 200, 300, 80, 20);

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            //cout << localPosition.x << endl;
            b1.moveCursor(localPosition.x, localPosition.y);
        }
        window.clear(sf::Color::Blue);
        window.draw(b1);

        window.display();
    }
} */
