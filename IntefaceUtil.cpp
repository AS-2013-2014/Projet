
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: Interface                                                     */
/*                                                                          */
/* Fonction(s): Interagir avec le joueur                                    */
/*--------------------------------------------------------------------------*/
/* Description: mettre ce qui à rapport direct a l'interface                */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

void pause()
{
	//mise en place de l'interface pause
	while (!handsIn());
	//mise en place de la fin de la pause
	cout<<"retour en jeu dans 3"<<endl;
	sfml::wait(1);
	cout<<"retour en jeu dans 2"<<endl;
	sfml::wait(1);
	cout<<"retour en jeu dans 1"<<endl;
	sfml::wait(1);
	cout<<"retour en jeu"<<endl;
}