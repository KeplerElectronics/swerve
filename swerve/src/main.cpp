/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Tank Drive                                                */
/*    This sample allows you to control a simple swerve drive using both      */
/*    joysticks. Adjust the deadband value for more accurate movements.       */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ld1                  motor         1               
// rd1                  motor         5               
// rd2                  motor         4               
// ld2                  motor         9               
// s1                   motor         10              
// s2                   motor         2               
// s3                   motor         7               
// s4                   motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

int spintest = 0; //0 none, 1 in spin, 2 reset

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  s1.resetRotation();
  s2.resetRotation();
  s3.resetRotation();
  s4.resetRotation();

}

void autonomous(void) {
 

}

void usercontrol(void) {
  
 

  while (true) {
  
    ld1.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
    ld2.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
    rd1.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
    rd2.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;

    s1.spin(directionType::fwd, Controller1.Axis1.value(), velocityUnits::pct); 
    s2.spin(directionType::fwd, Controller1.Axis1.value(), velocityUnits::pct); 
    s3.spin(directionType::fwd, Controller1.Axis1.value(), velocityUnits::pct); 
    s4.spin(directionType::fwd, Controller1.Axis1.value(), velocityUnits::pct); 
    
    if (Controller1.Axis1.value() == 0) {
      s1.stop(hold);
      s2.stop(hold);
      s3.stop(hold);
      s4.stop(hold);
    }

    if (Controller1.ButtonR2.pressing()) {
      s1.rotateTo(135, rotationUnits::deg, 100, velocityUnits::pct, false);
      s2.rotateTo(-135, rotationUnits::deg, 100, velocityUnits::pct, false);
      s3.rotateTo(135, rotationUnits::deg, 100, velocityUnits::pct, false);
      s4.rotateTo(-135, rotationUnits::deg, 100, velocityUnits::pct);
      spintest = 0;

    } else {
      if (spintest == 0) {
        s1.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct, false);
        s2.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct, false);
        s3.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct, false);
        s4.rotateTo(0, rotationUnits::deg, 100, velocityUnits::pct);
        spintest = 1;
      } else {

      }
    }

    task::sleep(20);

  }
}

 
int main(){
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  }

