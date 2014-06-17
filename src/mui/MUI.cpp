#include "MUI.hpp"



//Constructor
MUI::MUI(int width, int height) {
   controller = Leap::Controller();
   controller.addListener(*this);
   
   active = false;
   windowWidth = width;
   windowHeight = height;
   mode = MUI::MODE_ALL;
   lastJumpTime = 0;
   
   jumpNb = 0;
}






/**************************************
 ****Leap Motion (controller) Event****
 **************************************/

void MUI::onInit(const Leap::Controller& controller) {
   std::cout << "Initialized" << std::endl;
}

void MUI::onConnect(const Leap::Controller& controller) {
   std::cout << "Connected" << std::endl;
   active = true;
}

void MUI::onDisconnect(const Leap::Controller& controller) {
   //Note: not dispatched when running in a debugger.
   std::cout << "Disconnected" << std::endl;
   active = false;
}

void MUI::onExit(const Leap::Controller& controller) {
   std::cout << "Exited" << std::endl;
}

void MUI::onFocusGained(const Leap::Controller& controller) {
   std::cout << "Focus Gained" << std::endl;
}

void MUI::onFocusLost(const Leap::Controller& controller) {
   std::cout << "Focus Lost" << std::endl;
}



void MUI::onFrame(const Leap::Controller& controller) {
   const Leap::Frame frame = controller.frame();   
   
   switch (mode){
      
      //mode : all
      case MUI::MODE_ALL:
         updatePoint(frame, MUIEventList);
         getJump(frame, MUIEventList);
         updatePlatformMui (frame, MUIEventList);
         break;
   
      //mode : point
      case MUI::MODE_POINT:
         updatePoint(frame, MUIEventList);
         break;
   
      //mode : point2
      case MUI::MODE_POINT2:
         updatePoint2(frame, MUIEventList);
         break;
      
      //mode : jump
      case MUI::MODE_JUMP:
         getJump(frame, MUIEventList);
         break;
      
      //mode : platform
      case MUI::MODE_PLATFORM:
         updatePlatformMui (frame, MUIEventList);
         
         break;
         
   }
}



void MUI::setMode(MUI::Mode m) {
   mode = m;
   
   if (!controller.isGestureEnabled(Leap::Gesture::TYPE_SWIPE)) {
      controller.enableGesture(Leap::Gesture::TYPE_SWIPE, false);
      
      if (mode == MUI::MODE_JUMP || mode == MUI::MODE_ALL) {
         controller.enableGesture(Leap::Gesture::TYPE_SWIPE);
      }
   }
   
   if (!controller.isGestureEnabled(Leap::Gesture::TYPE_SCREEN_TAP)) {
      controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP, false);
      
      if (mode == MUI::MODE_POINT2) {
         
         controller.enableGesture(Leap::Gesture::TYPE_KEY_TAP);
         if(controller.config().setFloat("Gesture.KeyTap.MinDownVelocity", 70.0) &&
            controller.config().setFloat("Gesture.KeyTap.HistorySeconds", .1) &&
            controller.config().setFloat("Gesture.KeyTap.MinDistance", 3.0))
               controller.config().save();
         /*
         controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);
         if(controller.config().setFloat("Gesture.ScreenTap.MinForwardVelocity", 0.50) &&
            controller.config().setFloat("Gesture.ScreenTap.HistorySeconds", 0.1) &&
            controller.config().setFloat("Gesture.ScreenTap.MinDistance", 2000.0))
               
               controller.config().save();
         */
      }
   }
}






bool MUI::pollEvent(MUIEvent& evt) {
   if (!MUIEventList.empty()) {
      evt = MUIEventList.back();
      MUIEventList.pop_back();
      return true;
   }
   return false;
}






/*************************
 *****Other Functions*****
 *************************/



int MUI::countPointables(){
   return controller.frame().pointables().count();
}




//MODE POINT

void MUI::updatePoint(const Leap::Frame& frame, std::vector<MUIEvent>& MUIEventList){
   Leap::Pointable pointable = frame.pointables().frontmost();
   
   //GET EVENT
   Leap::Pointable::Zone newStatus = pointable.touchZone();
   if (pointStatus != newStatus) {
      switch (newStatus) {
         
         case Leap::Pointable::ZONE_NONE:
            std::cout << "Event : pointStatus : NONE" << std::endl;
            pointStatus = newStatus;
            MUIEventList.push_back ( MUIEvent(MUIEvent::POINT_EXIT) );
            break;
         
         case Leap::Pointable::ZONE_HOVERING:
            std::cout << "Event : pointStatus : HOVERING" << std::endl;
            pointStatus = newStatus;
            MUIEventList.push_back ( MUIEvent(MUIEvent::POINT_ENTER) );
            break;
         
         case Leap::Pointable::ZONE_TOUCHING:
            std::cout << "Event : pointStatus : TOUCHING" << std::endl;
            pointStatus = newStatus;
            MUIEventList.push_back ( MUIEvent(MUIEvent::POINT_TOUCH) );
            break;
      }
   }
   
   
   Leap::Vector stabilizedPosition = pointable.stabilizedTipPosition();
   
   Leap::InteractionBox iBox = frame.interactionBox();
   Leap::Vector normalizedPosition = iBox.normalizePoint(stabilizedPosition);
   
   float x = normalizedPosition.x * windowWidth;
   float y = windowHeight - normalizedPosition.y * windowHeight;
   
   float z = pointable.touchDistance();
   
   point = sf::Vector3f(x, y, z);
}



//MODE POINT2

void MUI::updatePoint2(const Leap::Frame& frame, std::vector<MUIEvent>& MUIEventList){
   Leap::Pointable pointable = frame.pointables().frontmost();
   
   //GET EVENT
   Leap::Pointable::Zone newStatus = pointable.touchZone();
   if (pointStatus != newStatus) {
      switch (newStatus) {
         
         case Leap::Pointable::ZONE_NONE:
            std::cout << "Event : pointStatus : NONE" << std::endl;
            pointStatus = newStatus;
            MUIEventList.push_back ( MUIEvent(MUIEvent::POINT_EXIT) );
            break;
         
         case Leap::Pointable::ZONE_HOVERING:
            std::cout << "Event : pointStatus : HOVERING" << std::endl;
            pointStatus = newStatus;
            MUIEventList.push_back ( MUIEvent(MUIEvent::POINT_ENTER) );
            break;
      }
   }
   
      
   Leap::Vector stabilizedPosition = pointable.stabilizedTipPosition();
   
   Leap::InteractionBox iBox = frame.interactionBox();
   Leap::Vector normalizedPosition = iBox.normalizePoint(stabilizedPosition);
   
   float x = normalizedPosition.x * windowWidth;
   float y = windowHeight - normalizedPosition.y * windowHeight;
   
   float z = pointable.touchDistance();
   
   point = sf::Vector3f(x, y, z);
   
   
   
   
   
   
   /*
   Leap::GestureList gestureList = frame.gestures();
   Leap::GestureList::const_iterator gl = gestureList.begin();
   
   while (gl != gestureList.end()) {
         std::cout << "oknvoeinroveibrvobervboerjv" << std::endl;
      //check if key tap
      if ((*gl).type() == Leap::Gesture::TYPE_SCREEN_TAP) {
         //check if valid
         if ((*gl).isValid()) {
            MUIEventList.push_back ( MUIEvent(MUIEvent::POINT_TOUCH) );
            std::cout << "position key tap x = " << iBox.normalizePoint(((Leap::ScreenTapGesture)(*gl)).position())[0]* windowWidth << std::endl;
            std::cout << "position key tap y = " << windowHeight - iBox.normalizePoint(((Leap::ScreenTapGesture)(*gl)).position())[1] * windowHeight << std::endl;
            std::cout << "position key tap z = " << iBox.normalizePoint(((Leap::ScreenTapGesture)(*gl)).position())[2] << std::endl;
         }
      }
      
      gl++;
   }
   */
   
   Leap::GestureList gestureList = frame.gestures();
   Leap::GestureList::const_iterator gl = gestureList.begin();
   
   while (gl != gestureList.end()) {
         std::cout << "oknvoeinroveibrvobervboerjv" << std::endl ;
      //check if key tap
      if ((*gl).type() == Leap::Gesture::TYPE_KEY_TAP) {
         
         
         //check if valid
         if ((*gl).isValid()) {
         
         //if ((*gl).state() == Leap::Gesture::STATE_START) {
         
            MUIEventList.push_back ( MUIEvent(MUIEvent::POINT_TOUCH) );
            std::cout << "position key tap x = " << iBox.normalizePoint(((Leap::KeyTapGesture)(*gl)).position())[0]* windowWidth << std::endl;
            std::cout << "position key tap y = " << windowHeight - iBox.normalizePoint(((Leap::KeyTapGesture)(*gl)).position())[1] * windowHeight << std::endl;
            std::cout << "position key tap z = " << iBox.normalizePoint(((Leap::KeyTapGesture)(*gl)).position())[2] << std::endl;
         }
      }
      
      gl++;
   }
   
}

















//MODE JUMP


void MUI::getJump (const Leap::Frame& frame, std::vector<MUIEvent>& MUIEventList){
   
   
   //Time limit between each jump
   if ((frame.timestamp() - lastJumpTime) > limitTime) {
      
      
      Leap::GestureList gestureList = frame.gestures();
      int32_t newId;
      Leap::Vector direction;
      
      bool jumped = false;
      Leap::GestureList::const_iterator gl = gestureList.begin();
      
      while (gl != gestureList.end() && !jumped) {
      
         //check if swipe
         if ((*gl).type() == Leap::Gesture::TYPE_SWIPE) {
            
                  
            //check if valid
            if ((*gl).isValid()) {
               
               
               if ((*gl).state() == Leap::Gesture::STATE_START) {
               
                  
                  //check if direction is right
                  direction = ((Leap::SwipeGesture)(*gl)).direction();
                  
                  if (direction.y > 0) {                  
                     //check if id is different
                     newId = (*gl).id();
                     
                     
                     if (newId != lastJumpId) {
                        lastJumpId = newId;
                        
                        MUIEventList.push_back ( MUIEvent(MUIEvent::JUMP) );
                        jumpNb+=1;
                        std::cout << "JUMP nbr :" << jumpNb << std::endl;
                        jumped = true;
                        lastJumpTime = frame.timestamp();
                     }
                  }
               }
            }
         }
         
         gl++;
      }
   }
}





//MODE PLATFORM


void MUI::updatePlatformMui(const Leap::Frame& frame, std::vector<MUIEvent>& MUIEventList){
   
   int nbPointables = countPointables();
   
   if (nbPointables >= 2){
      
      Leap::PointableList pointables = frame.pointables();
   
      Leap::Pointable pointable1;
      Leap::Pointable pointable2;
      
      //GET THE TWO FRONTMOST POINTABLES
      if (pointables[0].tipPosition().z < pointables[1].tipPosition().z){
         pointable1 = pointables[0];
         pointable2 = pointables[1];
      }
      else{
         pointable1 = pointables[1];
         pointable2 = pointables[0];         
      }
      
      
      //if more than 2 pointables take the two frontmost and put the frontmost in pointable1
      if (nbPointables > 2){
         for (int i=2; i<nbPointables; i++){
            float z = pointables[i].tipPosition().z;
            if (z < pointable2.tipPosition().z){
               if (z < pointable1.tipPosition().z){
                  pointable2 = pointable1;
                  pointable1 = pointables[i];
               }
               else {
                  pointable2 = pointables[i];
               }
            }
         }
      }
      
      
      //left pointable to pointable1 and right pointable to pointable2
      if (pointable1.tipPosition().x > pointable2.tipPosition().x) {
         Leap::Pointable pointableTmp = pointable1;
         pointable1 = pointable2;
         pointable2 = pointableTmp;
      }
      
      
      //GET EVENT
      Leap::Pointable::Zone newStatus1 = pointable1.touchZone();
      Leap::Pointable::Zone newStatus2 = pointable2.touchZone();
      
      
      if (newStatus1 == newStatus2) {
         if (platformMuiStatus != newStatus1) {
            switch (newStatus1) {
               
               case Leap::Pointable::ZONE_NONE:
                  std::cout << "Event : platformMuiStatus : NONE" << std::endl;
                  platformMuiStatus = newStatus1;
                  MUIEventList.push_back ( MUIEvent(MUIEvent::PLATFORM_EXIT) );
                  break;
               
               case Leap::Pointable::ZONE_HOVERING:
                  std::cout << "Event : platformMuiStatus : HOVERING" << std::endl;
                  platformMuiStatus = newStatus1;
                  MUIEventList.push_back ( MUIEvent(MUIEvent::PLATFORM_ENTER) );
                  break;
               
               case Leap::Pointable::ZONE_TOUCHING:
                  std::cout << "Event : platformMuiStatus : TOUCHING" << std::endl;
                  platformMuiStatus = newStatus1;
                  MUIEventList.push_back ( MUIEvent(MUIEvent::PLATFORM_CREATE) );
                  break;
            }
         }
      }
   
      
      
      //Normalization of pointables
      Leap::InteractionBox iBox = frame.interactionBox();
      
      Leap::Vector normalizedPointable1 = iBox.normalizePoint ( pointable1.stabilizedTipPosition() );
      Leap::Vector normalizedPointable2 = iBox.normalizePoint ( pointable2.stabilizedTipPosition() );
      
      
      platformMui.setX1(normalizedPointable1.x * windowWidth);
      platformMui.setX2(normalizedPointable2.x * windowWidth);
      
      platformMui.setY1(windowHeight - normalizedPointable1.y * windowHeight);
      platformMui.setY2(windowHeight - normalizedPointable2.y * windowHeight);
      
      platformMui.setZ((pointable1.touchDistance() + pointable2.touchDistance()) / 2);
      
      platformMui.setRotation(
            atan2(
               pointable2.tipPosition().y - pointable1.tipPosition().y, 
               pointable2.tipPosition().x - pointable1.tipPosition().x
            ) * (180/PI) *(-1) 
      );
   }
   
   
   
  
  
  
  
  
  
  
   
   
   
}







