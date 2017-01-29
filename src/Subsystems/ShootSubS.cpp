#include "ShootSubS.h"
#include "../RobotMap.h"
#include <Commands/Subsystem.h>

ShootSubS::ShootSubS() : Subsystem("ShootSubS") {
	cannon = new Spark(CANNON_MOTOR);
}

void ShootSubS::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ShootSubS::setFireSpeed(double Speed){
	cannon->Set(Speed);
}
