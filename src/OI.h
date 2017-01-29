#ifndef OI_H
#define OI_H

#include <Joystick.h>

class OI {
public:
	OI();
	Joystick* driverJoyStick;
	Joystick* cannonJoyStick;
};

#endif  // OI_H
