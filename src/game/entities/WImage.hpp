
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: graphic                                                       */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Une image de la scène (world image)                         */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef H_WIMAGE
#define H_WIMAGE

#include "Graphic.hpp"
#include "../../misc/Resources.hpp"

class WImage : public Graphic
{
	public:
		WImage(int x, int y, float z, int w, int h, int r, const std::string& file);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		sf::Sprite sprite;
};

#endif
