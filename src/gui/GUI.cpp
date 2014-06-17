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
#include "GUI.hpp"

GUI:: GUI(sf::RenderWindow  &window)
{
/****************************************************
 *       Textures, Sprites & Couleurs
 ***************************************************/
    // Texture menu
    sf::Texture menu;
    if (!menu.loadFromFile("img_menu.jpg"))
        cout << "Erreur texture menu" << endl;

    // Texture jouer
    sf::Texture jouer;
    if (!jouer.loadFromFile("img_jouer.jpg"))
        cout << "Erreur texture jouer" << endl;

    // Sprite fond
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(menu);

    // Déclaration des couleurs
    // sf::Color color = sf::Color(190,190,190,255);

/****************************************************
 *    FIN : Textures, Sprites & Couleurs
 ***************************************************/

    // variable ecran
    //int ecran = 0;

    // Déclaration des Boutons
/*    int x;
    int y1;
    int y2;
    int y3;
    int y4;
    int y5;
    x = (mainWindow.getSize().x - 400)/2;
    y1 = 80;
    y2 = 80 + 50 + 40;
    y3 = 80 + 50*2 + 40*2;
    y4 = 80 + 50*3 + 40*3;
    y5 = 80 + 50*4 + 40*4;
    RectangleButton rb1(x, y1, 400, 80,"JOUER");
    RectangleButton rb2(x, y2, 400, 80,"OPTIONS");
    RectangleButton rb3(x, y3, 400, 80,"AIDE");
    RectangleButton rb4(x, y4, 400, 80,"CREDITS");
    RectangleButton rb5(x, y5, 400, 80,"QUITTER");

    RectangleButton rb6(x, y1, 400, 80,"NOUVELLE PARTIE");
    RectangleButton rb7(x, y2, 400, 80,"CONTINUER");
    RectangleButton rb8(x, y3, 400, 80,"MONDE");

    RectangleButton rb9(x, y1, 400, 80,"TERRE");
    RectangleButton rb10(x, y2, 400, 80,"EAU - GLACE");
    RectangleButton rb11(x, y3, 400, 80,"AIR");
    RectangleButton rb12(x, y4, 400, 80,"FEU");

    RectangleButton rb13(x, y1, 400, 80,"NIVEAU 1");
    RectangleButton rb14(x, y2, 400, 80,"NIVEAU 2");
    RectangleButton rb15(x, y3, 400, 80,"NIVEAU 3");
    RectangleButton rb16(x, y4, 400, 80,"NIVEAU 4");

    RectangleButton rb17(x, y1, 400, 80,"SAUT");
    RectangleButton rb18(x, y2, 400, 80,"CREATION DE PLATEFORME");
    RectangleButton rb19(x, y3, 400, 80,"ASCENSEUR");
*/

  //Zone  de  test  : on  ajoute  un  bouton  à la  page  courante
  setPage[0] = Page();
  currentPage = setPage[0];
  currentPage.ajouterWidget(b1);

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

