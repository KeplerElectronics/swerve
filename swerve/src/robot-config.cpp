#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor ld1 = motor(PORT1, ratio18_1, false);
motor rd1 = motor(PORT5, ratio18_1, false);
motor rd2 = motor(PORT4, ratio18_1, false);
motor ld2 = motor(PORT9, ratio18_1, false);
motor s1 = motor(PORT10, ratio18_1, false);
motor s2 = motor(PORT2, ratio18_1, false);
motor s3 = motor(PORT7, ratio18_1, false);
motor s4 = motor(PORT8, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}