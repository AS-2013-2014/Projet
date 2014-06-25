
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: graphic                                                       */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Un élément graphique de la scène                            */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef H_GRAPHIC
#define H_GRAPHIC

#include "../Entity.hpp"
#include <SFML/Graphics.hpp>

class Graphic : public Entity
{
	public:
		Graphic(int x, int y, float z, int w, int h, int r);


		//pour réordonner un vector de pointeur de graphic
		static bool sort(Graphic *lhs, Graphic *rhs){
			return lhs->z > rhs->z;
		}

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
