/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: interface                                                     */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Interface graphique (Graphical User Interface)              */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
#include <vector>
#include "Page.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include  "Widget.hpp"

#ifndef H_GUI
#define H_GUI

class GUI
{
  std::vector<Page>    pageSet;
  Page currentPage;

public:
  //Constructeur  qui fait  tout
  GUI(sf::RenderWindow  &window)
  {
    //Zone  de  test  : on  ajoute  un  bouton  à la  page  courante
    RectangleButton b1( 0, 0, 800,600,"TEST BUTTON");
    b1.setColorButton(sf::Color::Blue);
    window.draw(b1);
    currentPage= Page();
    currentPage.ajouterWidget(b1);

    //Window.setKeyRepeatEnabled(false);


    //Game Loop
    while(window.isOpen())
      {
        sf::Event event;
        while(window.pollEvent(event))
          {
            //CodeHugo
            // Fermeture de la fenêtre
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
              {
                window.close();
              }
            // std::cout<<currentPage.monWidget.getLongueur()<<std::endl;
            // Clique sur fond
            if (event.type == sf::Event::MouseButtonReleased)
              {
                if (event.mouseButton.button == sf::Mouse::Left)
                  {
                    std::cout<<event.mouseButton.x<<std::endl;
                    std::cout<<event.mouseButton.y<<std::endl;
                    //On  va  tester  tous  nos widgets : 3 boucles pour  les 3 widgets
                    for(unsigned	int	i=0; i<currentPage.mesRect.size(); i++)
                      {
                        //Zone  de  test  : si  clic  dans  bouton
                        if(currentPage.mesRect[i].estDansButton(event.mouseButton.x, event.mouseButton.y))
                          {
                            std::cout << "Yes !!!!" << std::endl;
                          }
                        else
                          {
                            std::cout<<"No  !!!!"<<std::endl;
                          }

                      }
                    for(unsigned	int	i=0; i<currentPage.mesCircl.size(); i++)
                      {

                      }
                    for(unsigned	int	i=0; i<currentPage.mesSlid.size(); i++)
                      {

                      }
                  }
              }
          }
        window.display();
      }


  }

};

#endif
