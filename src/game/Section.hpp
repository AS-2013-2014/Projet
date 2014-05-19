
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
/* qu'avec les plateformes (mortelles ou non) de la section où il se trouve */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef SECTION
#define SECTION

#include <vector>
#include "entities/Platform.hpp"

class Section {
	public:
	std::vector<Platform*> platforms;
	Section();
};
#endif
