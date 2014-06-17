#ifndef H_MUIEVENT
#define H_MUIEVENT

#include <Leap.h>
#include <SFML/Graphics.hpp>


class MUIEvent {
   
   private:
      int type;
      //Motion motion;
   
   public:
      
      //Events
      enum Event {
         NONE = 0,
         POINT_ENTER = 1,
         POINT_EXIT = 2,
         POINT_TOUCH = 3,
         JUMP = 4,
         PLATFORM_ENTER = 5,
         PLATFORM_EXIT = 6,
         PLATFORM_CREATE = 7
      };
      
      //Constructors
      MUIEvent() {
         type = MUIEvent::NONE;
      }
      
      MUIEvent(MUIEvent::Event type) {
         this->type = type;
      }
      
      /* 
      MUIEvent(MUIEvent::Event type, Motion m) {
         type = c;
         motion = m;
      }
      */
      
      //Getters
      int getType(){
         return type;
      }
      
      /*
      Motion getMotion() {
         return motion;
      }
      */
      
};


#endif
