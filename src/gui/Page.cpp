#include "Page.hpp"

 void Page::draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
          // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
  states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

  // on applique la texture
  states.texture = NULL;

    for (int i = 0; i<(int)mesRect.size(); i++){
            target.draw(mesRect[i], states);
    }
  }

/*
int main()
{
    Page pge ;
    RectangleButton rect(450, 50, 200, 80,"RETOUR");
    pge.ajouterWidget(rect);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                {window.close();}
        }

        window.draw(pge);
        window.display();
    }


}
*/
