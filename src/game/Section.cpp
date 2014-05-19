
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): gérer les collisions                                        */
/*--------------------------------------------------------------------------*/
/* Description: le niveau courrant est divisé en sections,                  */
/* le moteur de collision ne teste les collisions du joueur                 */
/* qu'avec les plateformes (mortelles ou non) de section où il se trouve    */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#include "Section.hpp"

Section::Section(){}

Section::~Section()
{
	for(int i = 0; i < platforms.size(); i++)
		delete platforms[i];
}

