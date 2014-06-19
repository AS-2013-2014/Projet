/****************************************************************************/
/* DUT INFO AS - Projet AS */
/* */
/* */
/* Categorie: interface */
/* */
/* Fonction(s): */
/*--------------------------------------------------------------------------*/
/* Description: Interface graphique (Graphical User Interface) */
/* */
/* */
/* */
/* */
/****************************************************************************/
#include "GUI.hpp"

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
     // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
  states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

  // on applique la texture
  states.texture = NULL;
            target.draw(currentPage);


}



GUI::GUI(sf::RenderWindow &window, Game* game)
{
  pageSet= vector<Page>(15);
  /*********************************************************/
  /** Textures, Sprites & Couleurs **/
  /*********************************************************/
  /// à paramétrer avec les graphismes, code pour les tests
  // Texture main dans LM
  //sf::Texture handInLMTexture;
  //if (!handInLMTexture.loadFromFile("img_menu.jpg"))
  // cout << "Erreur texture handInLMTexture" << endl;
  // Texture fond principal
  sf::Texture* mainTexture;

  mainTexture = Resources::getTexture("images/fond.jpg");

  // Texture fond eau
  /*sf::Texture waterTexture;
  if (!waterTexture.loadFromFile("img_jouer.jpg"))
  cout << "Erreur texture waterTexture" << endl;
  // Texture fond air
  sf::Texture airTexture;
  if (!airTexture.loadFromFile("img_jouer.jpg"))
  cout << "Erreur texture airTexture" << endl;
  // Texture fond feu
  sf::Texture fireTexture;
  if (!fireTexture.loadFromFile("img_jouer.jpg"))
  cout << "Erreur texture fireTexture" << endl;
  */
  // Sprite fond
  sf::Sprite spriteBackground;
  spriteBackground.setTexture(*mainTexture);

  // Déclaration des couleurs
  // sf::Color color = sf::Color(190,190,190,255);

  /*********************************************************/
  /** Création des pages **/
  /*********************************************************/
  vector<RectangleButton> mesRectZ = vector<RectangleButton>(0);
  vector<RectangleButton> mesRectU = vector<RectangleButton>(1);
  vector<RectangleButton> mesRectT = vector<RectangleButton>(3);
  vector<RectangleButton> mesRectQ = vector<RectangleButton>(4);
  vector<RectangleButton> mesRectC = vector<RectangleButton>(5);
  vector<RectangleButton> mesRectS = vector<RectangleButton>(6);
  // Ajout du slider
  vector<Slider> mesSlide = vector<Slider> (1);

  pageSet[HANDINLM] = Page(mesRectZ,"");
  pageSet[PORTAL] = Page(mesRectZ,"");
  /*pageSet[HOME] = Page();
  pageSet[PLAY] = Page();
  pageSet[WORLDS] = Page();
  pageSet[EARTH] = Page();
  pageSet[WATER] = Page();
  pageSet[AIR] = Page();
  pageSet[FIRE] = Page();*/
  //pageSet[HELP] = Page();


  // Définition de la page courante
  /*currentPage = pageSet[HOME];
  int currentCode;
  currentCode = HOME;*/

  /*********************************************************/
  /** Assignation des fonds à chaque page **/
  /*********************************************************/


  /*********************************************************/
  /** Création des boutons pour chaque page **/
  /*********************************************************/
  // Position selon les coordonnées (x,y) du coin haut gauche du bouton rectangle
  int x; // identique pour tous les boutons
  int y1; // premier bouton
  int y2; // deuxième bouton
  int y3; // troisième bouton
  int y4; // quatrième bouton
  int y5; // cinquième bouton

  // x obtenu en divisant par 2 la largeur de la fenêtre moins la largeur d'un bouton
  x = (window.getSize().x - 400)/2;
  // 80 = marge haut
  // 80 = hauteur bouton
  // 40 = espace entre les boutons
  y1 = 50;
  y2 = 50 + 80 + 30;
  y3 = 50 + 80*2 + 30*2;
  y4 = 50 + 80*3 + 30*3;
  y5 = 50 + 80*4 + 30*4;

  //page  option
  mesRectU[0]=RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  mesSlide[0] = Slider (200, 300, 80, 20);
  pageSet[OPTION] = Page(mesRectU,mesSlide);

  //page  présentation  du  saut
  mesRectU[0]=RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  pageSet[JUMP] = Page(mesRectU,"");

  //page  présentation  dessiner  plateforme
  mesRectU[0]=RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  pageSet[CREATEDECK] = Page(mesRectU,"");

  //page  des crédits
  mesRectU[0]=RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  pageSet[CREDIT] = Page(mesRectU,"");

  // menu principal
  mesRectC[0] = RectangleButton (x, y1, 400, 80,"JOUER");
  mesRectC[1] = RectangleButton(x, y2, 400, 80,"OPTIONS");
  mesRectC[2] = RectangleButton(x, y3, 400, 80,"AIDE");
  mesRectC[3] = RectangleButton(x, y4, 400, 80,"CREDITS");
  mesRectC[4] = RectangleButton(x, y5, 400, 80,"QUITTER");
  //mesRectS[5] = RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  pageSet[HOME] = Page(mesRectC,"");


  // menu jouer
  mesRectQ[0] = RectangleButton(x, y1, 400, 80,"NOUVELLE PARTIE");
  mesRectQ[1] = RectangleButton(x, y2, 400, 80,"CONTINUER");
  mesRectQ[2] = RectangleButton(x, y3, 400, 80,"MONDE");
  mesRectQ[3] = RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
      pageSet[PLAY] = Page(mesRectQ,"");


  // menu mondes
  mesRectC[0] = RectangleButton(x, y1, 400, 80,"TERRE");
  mesRectC[1] = RectangleButton(x, y2, 400, 80,"EAU - GLACE");
  mesRectC[2] = RectangleButton(x, y3, 400, 80,"AIR");
  mesRectC[3] = RectangleButton(x, y4, 400, 80,"FEU");
  mesRectC[4] = RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  pageSet[WORLDS] = Page(mesRectC,"");

  // menus niveaux
  mesRectC[0] = RectangleButton(x, y1, 400, 80,"NIVEAU 1");
  mesRectC[1] = RectangleButton(x, y2, 400, 80,"NIVEAU 2");
  mesRectC[2] = RectangleButton(x, y3, 400, 80,"NIVEAU 3");
  mesRectC[3] = RectangleButton(x, y4, 400, 80,"NIVEAU 4");
  mesRectC[4] = RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  pageSet[EARTH] = Page(mesRectC,"");
  pageSet[WATER] = Page(mesRectC,"");
  pageSet[AIR] = Page(mesRectC,"");
  pageSet[FIRE] = Page(mesRectC,"");

  // menu aide
  mesRectT[0] = RectangleButton(x, y1, 400, 80,"SAUT");
  mesRectT[1] = RectangleButton(x, y2, 400, 80,"CREATION DE PLATEFORME");
  mesRectT[2] = RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  pageSet[HELP] = Page(mesRectT,"");

  // page courante
  currentPage = pageSet[HOME];
  int currentCode;
  currentCode = HOME;

  // variable pour les boucles for
  unsigned int i;

  //monde selectionné
  int world = 1;

  bool running = true;

  cout << "creation des pages et des boutons reussie" << endl << "boucle de jeu" << endl;
  //Game Loop
  while(window.isOpen() && running)
    {
      /**** Cycle de la fenêtre : Clear - Draw - Display ****/
      window.clear(sf::Color::Black);

      /*** Gestionnaire des événements ***/
      sf::Event event;
      while (window.pollEvent(event))
        {
          /// à supprimer une fois GUI terminée ==> on ne quitte qu'avec le LM
          // Fermeture de la fenêtre
          if (event.type == sf::Event::Closed)
            {
              window.close();
            }

          /**
          Bouton retour à créer, code juste pour gestion lors des tests
          **/
          // Retour écran précédent
          if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
              cout<<"echap"<<endl;

              switch(currentCode)
                {
                case PLAY:
                  currentPage = pageSet[HOME];
                  currentCode=HOME;
                  break;
                case WORLDS:
                  currentPage = pageSet[PLAY];
                  spriteBackground.setTexture(*mainTexture);
                  currentCode=PLAY;
                  break;
                case EARTH:
                  currentPage = pageSet[WORLDS];
                  currentCode=WORLDS;
                  break;
                case WATER:
                  currentPage = pageSet[WORLDS];
                  currentCode=WORLDS;
                  break;
                case AIR:
                  currentPage = pageSet[WORLDS];
                  currentCode=WORLDS;
                  break;
                case FIRE:
                  currentPage = pageSet[WORLDS];
                  currentCode=WORLDS;
                  break;
                case OPTION:
                  currentPage = pageSet[HOME];
                  currentCode=HOME;

                  break;
                case HELP:
                  currentPage = pageSet[HOME];
                  currentCode=HOME;
                  break;
                case JUMP:
                  currentPage = pageSet[HELP];
                  currentCode=HELP;
                  break;
                case CREATEDECK:
                  currentPage = pageSet[HELP];
                  currentCode=HELP;
                  break;
                default:
                  currentPage = pageSet[HOME];
                  currentCode=HOME;
                  break;
                }
            }
          // Clique sur bouton
          if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
              cout << "il y a un clique gauche" << endl;
              //On va tester tous nos widgets : 3 boucles pour les 3 widgets
              for(i=0; i<currentPage.mesRect.size(); i++)
                {
                  cout << "boucle for des boutons rectangles" << endl;
                  //Zone de test : si clic dans bouton
                  if(currentPage.mesRect[i].estDansButton(event.mouseButton.x, event.mouseButton.y))
                    {
                      // premier bouton
                      if(i == 0)
                        {
                          cout << "test premier bouton" << endl;
                          switch(currentCode)
                            {
                            case HOME:
                              currentPage = pageSet[PLAY];
                              currentCode=PLAY;
                              break;
                            case PLAY:
                              /// NOUVELLE PARTIE
                              //currentPage = pageSet[HOME];
                              //lance une partie au dernier niveau débloqué
                              running = false;
                              game->load(game->getDataUnlockedWorld(), game->getDataUnlockedLevel());
                              break;
                            case WORLDS:
                              currentPage = pageSet[EARTH];
                              currentCode=EARTH;
                              spriteBackground.setTexture(*mainTexture);
                              world=1;
                              break;
                            case HELP:
                              currentPage = pageSet[JUMP];
                              currentCode=JUMP;
                              break;
                            case  OPTION:
                            {
                              int percent = currentPage.mesSlide[0].getCursorPosition()*100/currentPage.mesSlide[0].getWidth();
                              game->setDataVolume(percent);
                              std::cout << percent << std::endl;
                              currentPage=pageSet[HOME];
                              currentCode=HOME;
                            }
                              break;
                            case  CREDIT:
                              currentPage=pageSet[HOME];
                              currentCode=HOME;
                              break;
                            case  JUMP:
                              currentPage=pageSet[HELP];
                              currentCode=HELP;
                              break;
                            case  CREATEDECK:
                              currentPage=pageSet[HELP];
                              currentCode=HELP;
                              break;
                            default:
                              currentPage = pageSet[HOME];
                              currentCode=HOME;
                              game->load(world, 1);
                              running = false;
                              break;
                            }
                        }
                      // deuxième bouton
                      else if(i == 1)
                        {
                          cout << "test deuxieme bouton" << endl;
                          switch(currentCode)
                            {
                            case HOME:
                              currentPage = pageSet[OPTION];
                              currentCode=OPTION;
                              break;
                            case PLAY:
                              /// REPRENDRE
                              //currentPage = pageSet[HOME];
                              break;
                            case WORLDS:
                              currentPage = pageSet[WATER];
                              spriteBackground.setTexture(*mainTexture);
                              currentCode=WATER;
                              world=2;
                              break;
                            case HELP:
                              currentPage = pageSet[CREATEDECK];
                              currentCode=CREATEDECK;
                              break;
                            default:
                              currentPage = pageSet[HOME];
                              currentCode=HOME;
                             game->load(world, 2);
                              running = false;
                              break;
                            }
                        }
                      // troisième bouton
                      else if(i == 2)
                        {
                          cout << "test troisieme bouton" << endl;
                          switch(currentCode)
                            {
                            case HOME:
                              currentPage = pageSet[HELP];
                              currentCode=HELP;
                              break;
                            case PLAY:
                              currentPage = pageSet[WORLDS];
                              currentCode=WORLDS;
                              spriteBackground.setTexture(*mainTexture);
                              break;
                            case  HELP://Bouton  Retour
                              currentPage=pageSet[HOME];
                              currentCode=HOME;
                              break;
                            case WORLDS:
                              currentPage = pageSet[AIR];
                              currentCode=AIR;
                              spriteBackground.setTexture(*mainTexture);
                              world=3;
                              break;
                              default:
                                currentPage = pageSet[HOME];
                                currentCode=HOME;
                              game->load(world, 3);
                              running = false;
                                break;
                            }
                        }
                      // quatrième bouton
                      else if(i == 3)
                        {
                          cout << "test quatrieme bouton" << endl;
                          switch(currentCode)
                            {
                            case HOME:
                              currentPage = pageSet[CREDIT];
                              currentCode=CREDIT;
                              break;
                            case  PLAY://Bouton Retour
                              currentPage=pageSet[HOME];
                              currentCode=HOME;
                              break;
                            case WORLDS:
                              currentPage = pageSet[FIRE];
                              currentCode=FIRE;
                              spriteBackground.setTexture(*mainTexture);
                              world=4;
                              break;

                            default:
                              currentPage = pageSet[HOME];
                              currentCode=HOME;
                              game->load(world, 4);
                              running = false;
                              break;
                            }
                        }
                      // cinquième bouton
                      else if(i == 4)
                        {
                          cout << "test cinquieme bouton" << endl;
                          switch(currentCode)
                            {
                            case HOME://Bouton  Quitter
                              window.close();
                              break;
                            case  WORLDS://Bouton  Retour
                              spriteBackground.setTexture(*mainTexture);
                              currentPage=pageSet[PLAY];
                              currentCode=PLAY;
                              break;
                            case EARTH://Bouton  Retour
                              currentPage = pageSet[WORLDS];
                              currentCode=WORLDS;
                              break;
                            case WATER://Bouton  Retour
                              currentPage = pageSet[WORLDS];
                              currentCode=WORLDS;
                              break;
                            case AIR://Bouton  Retour
                              currentPage = pageSet[WORLDS];
                              currentCode=WORLDS;
                              break;
                            case FIRE://Bouton  Retour
                              currentPage = pageSet[WORLDS];
                              currentCode=WORLDS;
                              break;
                            default:
                              currentPage = pageSet[HOME];
                              currentCode=HOME;
                              running = false;
                              break;
                            }
                        }
                    }
                }
              /// pas encore implémenté !
              /*for(i=0; i<currentPage.mesCircl.size(); i++)
              {

              } */
              for(i=0; i<currentPage.mesSlide.size(); i++)
              {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                currentPage.mesSlide[i].moveCursor(localPosition.x, localPosition.y);
              }
            }
        }

      /// on a la page courante, on dessine le fond puis les boutons
      window.draw(spriteBackground);
      //cout << "dessins " << currentPage.mesRect.size() << endl;
      for(i=0; i<currentPage.mesRect.size(); i++)
        {
          //cout << "rectangle" << i << endl;
          window.draw(currentPage);
        }
      /*for(i=0; i<currentPage.mesCircl.size(); i++)
      {
      // window.draw(currentPage.mesCircl[i]);
      } */
      for(i=0; i<currentPage.mesSlide.size(); i++)
      {
        window.draw(currentPage.mesSlide[i]);
      }

      window.display();
    }
}
