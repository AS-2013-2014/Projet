#ifndef SLIDE
#define SLIDE



#define BMOINS 0
#define BPLUS 1
#define AILLEURS -1

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "RectangleButton.hpp"
//#include <SoundSource.hpp>

using namespace std;
class Slider : public sf::Drawable, public sf::Transformable
{
    // Attributs pour définir le bouton
    // le rectangle
    // rectangle du curseur
    sf::RectangleShape rect;
    // curseur
    sf::RectangleShape cursor;
    // differentes position du cureur
    sf::Vertex line0[2];
    sf::Vertex line1[2];
    sf::Vertex line2[2];
    sf::Vertex line3[2];
    sf::Vertex line4[2];
    sf::Vertex line5[2];
    // info en plus
        int ecart;
        int positionCursor;
        int x;
    // definition des boutton plus et moins
    public :
    RectangleButton bPlus;
    RectangleButton bMoins;
    sf::Event event;
    int _x;
    int _y;
    int _width;
    int _height;


// bMoins(-100, 0,50, 50, "-"), bPlus( 400, 0, 50, 50, "+")


public:
    Slider () {};
    Slider(int x1, int y, int width, int height) : bMoins( -(height + width/5) , 0, height, height, "-"), bPlus( width + (width/5) , 0, height, height, "+")
    {
        _x = x1;
        _y = y;
        _width = width;
        _height = height;

        // Définition de la taille du rectangle
        rect.setSize(sf::Vector2f(_width, _height));
        setPosition(sf::Vector2f(_x,_y));
        rect.setFillColor(sf::Color::Black);

        positionCursor = 0;


        // definition du cursors
        cout<<_x << " " << _y << endl;
        cursor.setSize(sf::Vector2f(1.5 * _height, (0.07*(1.5*_height))));
        cursor.setPosition(sf::Vector2f(positionCursor, (_height - 1.5*_height)/2 ));
        cursor.rotate(90);

        //void setColorButton(sf::Color color);
        // Coordonnées d'un cran
        ecart = _width / 5 ;
        int x1Slide = _x + ecart;
        int y1Slide = _y;
        int y2Slide = _y + _height;

        // Définition des lignes de différentes positions

        line0 [0] = sf::Vertex(sf::Vector2f(_x, _y));
        line0 [1] = sf::Vertex(sf::Vector2f(_x, y2Slide ));


        line1 [0] = sf::Vertex(sf::Vector2f(x1Slide, y1Slide ));
        line1 [1] = sf::Vertex(sf::Vector2f(x1Slide, y2Slide ));


        x1Slide += ecart;
        line2 [0] =  sf::Vertex(sf::Vector2f(x1Slide, y1Slide ));
        line2 [1] =  sf::Vertex(sf::Vector2f(x1Slide, y2Slide ));


        x1Slide += ecart;
        line3 [0] = sf::Vertex(sf::Vector2f(x1Slide, y1Slide ));
        line3 [1] = sf::Vertex(sf::Vector2f(x1Slide, y2Slide ));


        x1Slide += ecart;
        line4 [0] =  sf::Vertex(sf::Vector2f(x1Slide, y1Slide ));
        line4 [1] =  sf::Vertex(sf::Vector2f(x1Slide, y2Slide ));

        x1Slide += ecart;
        line5 [0] =  sf::Vertex(sf::Vector2f(x1Slide, y1Slide ));
        line5 [1] =  sf::Vertex(sf::Vector2f(x1Slide, y2Slide ));


    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setCursorPosition (int val);
    int getCursorPosition ();
    void moveCursor (int x, int y);
    bool estDansSlide (int xSouris, int ySouris);
    int ouDansSlide (int xSouris, int ySouris);
};


#endif
