#include "PlatformMui.hpp"


PlatformMui::PlatformMui(const Leap::Vector& f1, const Leap::Vector& f2){
   p1.x = f1[0];
   p1.y = f1[1];
   p2.x = f2[0];
   p2.y = f2[1];
   z = (f1[2]+f2[2])/2;
}


PlatformMui::PlatformMui(){
	p1.x=0;
	p1.y=0;
	p2.x=0;
	p2.y=0;
	z = 0;
}


PlatformMui::PlatformMui(float x1, float y1, float z1, float x2, float y2, float z2){
	p1.x=x1;
	p1.y=y1;
	p2.x=x2;
	p2.y=y2;
	z = (z1+z2)/2;
}


