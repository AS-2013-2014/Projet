﻿
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: moteur physique                                               */
/*                                                                          */
/* Fonction(s): recupération coordonées                                     */
/*--------------------------------------------------------------------------*/
/* Description:  classe mère de toutes les entitées                         */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef ENTITY
#define ENTITY
#include <SFML/Graphics.hpp>

	class Entity{
		protected:
			sf::Vector2i coord;
			float z;
			

		public:
			sf::RectangleShape rect;
			Entity(sf:Vector2i coord , float z , int length , int width);
			Entity(int x , int y , float z , int length , int width));
			sf::Vector2i getCoord() const;
			int getX()const;
			int getY()const;
			float getZ() const;
	};

#endif
