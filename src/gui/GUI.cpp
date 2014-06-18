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

GUI:: GUI(sf::RenderWindow &window)
{
  /*********************************************************/
  /** Textures, Sprites & Couleurs **/
  /*********************************************************/
  /// à paramétrer avec les graphismes, code pour les tests
  // Texture main dans LM
  //sf::Texture handInLMTexture;
  //if (!handInLMTexture.loadFromFile("img_menu.jpg"))
  // cout << "Erreur texture handInLMTexture" << endl;
  // Texture fond principal
  sf::Texture mainTexture;
  if (!mainTexture.loadFromFile("image/img_menu.jpg"))
    cout << "Erreur texture mainTexture" << endl;

  // Texture fond terre
  sf::Texture earthTexture;
  if (!earthTexture.loadFromFile("image/img_jouer.jpg"))
    cout << "Erreur texture earthTexture" << endl;
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
  spriteBackground.setTexture(mainTexture);

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

  // Pages avec zéro bouton
  pageSet[HANDINLM] = Page(mesRectZ);
  pageSet[PORTAL] = Page(mesRectZ);

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

  // constantes pour le calcul des positions y
  int const MARGINTOP(50);              // marge haut
  int const HEIGHTBUTTON(80);           // hauteur bouton
  int const SPACEBETWEENBUTTONS(30);    // espace entre les boutons

  y1 = MARGINTOP;
  y2 = MARGINTOP + HEIGHTBUTTON + SPACEBETWEENBUTTONS;
  y3 = MARGINTOP + HEIGHTBUTTON*2 + SPACEBETWEENBUTTONS*2;
  y4 = MARGINTOP + HEIGHTBUTTON*3 + SPACEBETWEENBUTTONS*3;
  y5 = MARGINTOP + HEIGHTBUTTON*4 + SPACEBETWEENBUTTONS*4;

  // constantes taille bouton
  int const WIDTHBUTTON(400);
  //page  option
  mesRectU[0]=RectangleButton(x+450, y5+50, 200, HEIGHTBUTTON,"RETOUR");
  pageSet[OPTION] = Page(mesRectU);

  //page  présentation  du  saut
  mesRectU[0]=RectangleButton(x+450, y5+50, 200, HEIGHTBUTTON,"RETOUR");
  pageSet[JUMP] = Page(mesRectU);

  //page  présentation  dessiner  plateforme
  mesRectU[0]=RectangleButton(x+450, y5+50, 200, HEIGHTBUTTON,"RETOUR");
  pageSet[CREATEDECK] = Page(mesRectU);

  //page  des crédits
  mesRectU[0]=RectangleButton(x+450, y5+50, 200, HEIGHTBUTTON,"RETOUR");
  pageSet[CREDIT] = Page(mesRectU);

  // menu principal
  mesRectC[0] = RectangleButton(x, y1, WIDTHBUTTON, HEIGHTBUTTON,"JOUER");
  mesRectC[1] = RectangleButton(x, y2, WIDTHBUTTON, HEIGHTBUTTON,"OPTIONS");
  mesRectC[2] = RectangleButton(x, y3, WIDTHBUTTON, HEIGHTBUTTON,"AIDE");
  mesRectC[3] = RectangleButton(x, y4, WIDTHBUTTON, HEIGHTBUTTON,"CREDITS");
  mesRectC[4] = RectangleButton(x, y5, WIDTHBUTTON, HEIGHTBUTTON,"QUITTER");
  //mesRectS[5] = RectangleButton(x+450, y5+50, 200, 80,"RETOUR");
  pageSet[HOME] = Page(mesRectC);


  // menu jouer
  mesRectQ[0] = RectangleButton(x, y1, WIDTHBUTTON, HEIGHTBUTTON,"NOUVELLE PARTIE");
  mesRectQ[1] = RectangleButton(x, y2, WIDTHBUTTON, HEIGHTBUTTON,"CONTINUER");
  mesRectQ[2] = RectangleButton(x, y3, WIDTHBUTTON, HEIGHTBUTTON,"MONDE");
  mesRectQ[3] = RectangleButton(x+450, y5+50, 200, HEIGHTBUTTON,"RETOUR");
  pageSet[PLAY] = Page(mesRectQ);

  // menu mondes
  mesRectC[0] = RectangleButton(x, y1, WIDTHBUTTON, HEIGHTBUTTON,"TERRE");
  mesRectC[1] = RectangleButton(x, y2, WIDTHBUTTON, HEIGHTBUTTON,"EAU - GLACE");
  mesRectC[2] = RectangleButton(x, y3, WIDTHBUTTON, HEIGHTBUTTON,"AIR");
  mesRectC[3] = RectangleButton(x, y4, WIDTHBUTTON, HEIGHTBUTTON,"FEU");
  mesRectC[4] = RectangleButton(x+450, y5+50, 200, HEIGHTBUTTON,"RETOUR");
  pageSet[WORLDS] = Page(mesRectC);

  // menus niveaux
  mesRectC[0] = RectangleButton(x, y1, WIDTHBUTTON, HEIGHTBUTTON,"NIVEAU 1");
  mesRectC[1] = RectangleButton(x, y2, WIDTHBUTTON, HEIGHTBUTTON,"NIVEAU 2");
  mesRectC[2] = RectangleButton(x, y3, WIDTHBUTTON, HEIGHTBUTTON,"NIVEAU 3");
  mesRectC[3] = RectangleButton(x, y4, WIDTHBUTTON, HEIGHTBUTTON,"NIVEAU 4");
  mesRectC[4] = RectangleButton(x+450, y5+50, 200, HEIGHTBUTTON,"RETOUR");
  pageSet[EARTH] = Page(mesRectC);
  pageSet[WATER] = Page(mesRectC);
  pageSet[AIR] = Page(mesRectC);
  pageSet[FIRE] = Page(mesRectC);

  // menu aide
  mesRectT[0] = RectangleButton(x, y1, WIDTHBUTTON, HEIGHTBUTTON,"SAUT");
  mesRectT[1] = RectangleButton(x, y2, WIDTHBUTTON, HEIGHTBUTTON,"CREATION DE PLATEFORME");
  mesRectT[2] = RectangleButton(x+450, y5+50, 200, HEIGHTBUTTON,"RETOUR");
  pageSet[HELP] = Page(mesRectT);

  // page courante
  currentPage = pageSet[HOME];
  int currentCode;
  currentCode = HOME;

  // variable pour les boucles for
  unsigned int i;

  cout << "creation des pages et des boutons reussie" << endl << "boucle de jeu" << endl;
  //Game Loop
  while(window.isOpen())
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
                  spriteBackground.setTexture(mainTexture);
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
                              break;
                            case WORLDS:
                              currentPage = pageSet[EARTH];
                              currentCode=EARTH;
                              spriteBackground.setTexture(earthTexture);
                              break;
                            case HELP:
                              currentPage = pageSet[JUMP];
                              currentCode=JUMP;
                              break;
                            case  OPTION:
                              currentPage=pageSet[HOME];
                              currentCode=HOME;
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
                              /// REPRENDRE au dernier niveau
                              //currentPage = pageSet[HOME];
                              break;
                            case WORLDS:
                              currentPage = pageSet[WATER];
                              spriteBackground.setTexture(earthTexture);
                              currentCode=WATER;
                              break;
                            case HELP:
                              currentPage = pageSet[CREATEDECK];
                              currentCode=CREATEDECK;
                              break;
                            default:
                              currentPage = pageSet[HOME];
                              currentCode=HOME;
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
                              spriteBackground.setTexture(earthTexture);
                              break;
                            case  HELP://Bouton  Retour
                              currentPage=pageSet[HOME];
                              currentCode=HOME;
                              break;
                            case WORLDS:
                              currentPage = pageSet[AIR];
                              currentCode=AIR;
                              spriteBackground.setTexture(earthTexture);
                              break;
                              default:
                                currentPage = pageSet[HOME];
                                currentCode=HOME;
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
                              spriteBackground.setTexture(earthTexture);
                              break;
                            default:
                              currentPage = pageSet[HOME];
                              currentCode=HOME;
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
                              spriteBackground.setTexture(mainTexture);
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
                              break;
                            }
                        }
                    }
                }
              /// pas encore implémenté !
              /*for(i=0; i<currentPage.mesCircl.size(); i++)
              {

              }
              for(i=0; i<currentPage.mesSlid.size(); i++)
              {

              }*/
            }
        }

      /// on a la page courante, on dessine le fond puis les boutons
      window.draw(spriteBackground);
      //cout << "dessins " << currentPage.mesRect.size() << endl;
      for(i=0; i<currentPage.mesRect.size(); i++)
        {
          //cout << "rectangle" << i << endl;
          window.draw(currentPage.mesRect[i]);
        }
      /*for(i=0; i<currentPage.mesCircl.size(); i++)
      {
      // window.draw(currentPage.mesCircl[i]);
      }
      for(i=0; i<currentPage.mesSlid.size(); i++)
      {
      //window.draw(currentPage.mesSlid[i]);
      }*/

      window.display();
    }
}
