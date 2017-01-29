#include "OI.h"

#include <WPILib.h>
#include "Commands/CannonFireCmd.h"

OI::OI() {
	// Process operator interface input here.

	driverJoyStick = new frc::Joystick(0);
	cannonJoyStick = new frc::Joystick(1);

	// Set buttons
    frc::JoystickButton* triggerBtn = new frc::JoystickButton(cannonJoyStick,1);
    //frc::JoystickButton* button11 = new frc::JoystickButton(cannonJoyStick, 11);


    triggerBtn->WhileHeld(new CannonFireCmd());

}
