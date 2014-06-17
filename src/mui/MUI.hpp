
/****************************************************************************/
/*                       DUT INFO AS - Projet AS                            */
/*                                                                          */
/*                                                                          */
/* Categorie: leap motion                                                   */
/*                                                                          */
/* Fonction(s):                                                             */
/*--------------------------------------------------------------------------*/
/* Description: Interface LeapMotion (Motion User Interface):               */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

#ifndef H_MUI
#define H_MUI

#include <Leap.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "MUIEvent.hpp"
#include "PlatformMui.hpp"

#include <iostream>

#define limitTime 60000

#define PI 3.14


class MUI : public Leap::Listener{
   
   private:
      bool active;
      
      //saves the application's widow size to adapt coordinates
      int windowWidth;
      int windowHeight;
      
      //status of the point
      Leap::Pointable::Zone pointStatus;
      Leap::Pointable::Zone platformMuiStatus;
      
      //backmost point (finger or tool)
      //x and y represent stabilized coordinates
      //z represents the distance from the touch zone values between -1 and 1
      sf::Vector3f point;
      
      
      //List of Event
      std::vector<MUIEvent> MUIEventList;
      
      //Last Gesture's ID
      int32_t lastJumpId;
      int jumpNb;
      
      //Leap Motion Mode
      int mode;
      
      //controller
      Leap::Controller controller;
      
      //time of the last detected jump
      float lastJumpTime;
      
      //platform
      PlatformMui platformMui;
      
      
   public:
      //Constructor
      MUI(int width, int height);
      
      //Destructor
      ~MUI() {
         controller.removeListener(*this);
      }
      
      
      //List of Leap Motion Mode
      enum Mode {
         MODE_ALL = 0,
         MODE_POINT = 1,
         MODE_JUMP = 2,
         MODE_PLATFORM = 3,
         MODE_POINT2 = 4
      };
      
      
      
      //Function for controller events
      void onInit(const Leap::Controller&);
      void onConnect(const Leap::Controller&);
      void onDisconnect(const Leap::Controller&);
      void onExit(const Leap::Controller&);
      void onFrame(const Leap::Controller&);
      void onFocusGained(const Leap::Controller&);
      void onFocusLost(const Leap::Controller&);
      
      void setMode(MUI::Mode);
      
      //public getter
      bool isActive(){ return active; }
      int getMode() { return mode; }
      bool pollEvent(MUIEvent& evt);
      sf::Vector3f getPoint() { return point; }
      PlatformMui getPlatform(){ return platformMui; }
      
   private:
      //functions to update motions
      void updatePoint(const Leap::Frame&, std::vector<MUIEvent>&);
      void updatePoint2(const Leap::Frame&, std::vector<MUIEvent>&);
      void updatePlatformMui(const Leap::Frame&, std::vector<MUIEvent>&);
      void getJump (const Leap::Frame& frame, std::vector<MUIEvent>&);
      
      int countPointables();
};

#endif
