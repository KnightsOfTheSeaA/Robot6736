#include "CannonFireCmd.h"

CannonFireCmd::CannonFireCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::shootSubS);
}

// Called just before this Command runs the first time
void CannonFireCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CannonFireCmd::Execute() {
	CommandBase::shootSubS->setFireSpeed(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool CannonFireCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CannonFireCmd::End() {
	CommandBase::shootSubS->setFireSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CannonFireCmd::Interrupted() {
	CommandBase::shootSubS->setFireSpeed(0);
}
