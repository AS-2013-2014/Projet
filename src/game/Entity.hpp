﻿/****************************************************************************/
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

class Entity : public sf::Drawable, public sf::Transformable{
	protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f coord;
	float z, angle;
  int type;
	sf::Vector2f size;
  bool visible;

	public:
	Entity(sf::Vector2f coord , float z , int length , int width, float angle);
	Entity(int x , int y , float z , int length , int width, float angle);

	// pour réordonner un vector de pointeur d'entités
	static bool sort(Entity *lhs, Entity *rhs){
		return lhs->getZ() > rhs->getZ();
	}

	virtual void frame(float time){}

	sf::Vector2f getCoord() const;
	int getX() const;
	int getY() const;
	float getZ() const;
	int getLength() const;
	int getWidth() const;
	float getAngle() const;
  int getEType(){ return type; }
  void setEType(int t){ type = t; }

  bool isVisible(){ return visible; }
  void setVisible(bool v){ visible = v; }

  enum{
    NONE=1,
    SOLID=2,
    PLATFORM=3,
    PLAYER=4
  };
};

#endif
