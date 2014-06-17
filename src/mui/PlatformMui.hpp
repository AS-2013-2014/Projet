#ifndef PLATFORMMUI_H
#define PLATFORMMUI_H

#include <Leap.h>
#include <SFML/Graphics.hpp>
#include <cmath>

class PlatformMui{
   private:
      sf::Vector2f p1;
      sf::Vector2f p2;
		float z;
		float rotation;
      

   public:
		PlatformMui();
      PlatformMui(const Leap::Vector& f1, const Leap::Vector& f2);
		PlatformMui(float x1, float y1, float z1, float x2, float y2, float z2);
		
		//Getters
		sf::Vector2f getPositionP1(){
			return p1;
		}

		sf::Vector2f getPositionP2(){
			return p2;
		}

		float getLength(){
			return sqrt( (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y) );
		}

		float getZ(){
			return z;
		}
		
		float getRotation() {
		   return rotation;
		}
		
		
		//Setters
		void setX1(float x1){
		   p1.x = x1;
		}
		
		void setX2(float x2){
		   p2.x = x2;
		}
		
		
		void setY1(float y1){
		   p1.y = y1;
		}
		
		void setY2(float y2){
		   p2.y = y2;
		}
		
		void setZ(float _z){
		   z = _z;
		}
		
		void setRotation(float _rotation) {
		   rotation = _rotation;
		}
};

#endif
