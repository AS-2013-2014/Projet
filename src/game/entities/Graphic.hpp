
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

//#include "../Entity.hpp"
#include <SFML/Graphics.hpp>

class Graphic : public sf::Drawable, public sf::Transformable//: public Entity
{
	public:
		Graphic(int x, int y, float z, int w, int h, int r);

		float z;
		int x,y,w,h,r;

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
