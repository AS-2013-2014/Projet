
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: main                                                          */
/*                                                                          */
/* Fonction(s):  main                                                       */
/*--------------------------------------------------------------------------*/
/* Description:  main                                                       */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "InterfaceUtil.hpp"
#include "MotionInterface.hpp"

int main()
{
	// initialisation
	//début boucle evenement
		
		//Gestion pause
			if (!handsIn())
				{
					pause();
				}
		
	//fin boucle evenement
	
	return 0;
}