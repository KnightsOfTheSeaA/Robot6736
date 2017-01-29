#include "Drive.h"

#include <SmartDashboard/SmartDashboard.h>

Drive::Drive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::driveSubS);
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	CommandBase::driveSubS->robotDrive->ArcadeDrive(CommandBase::oi->driverJoyStick);
	SmartDashboard::PutNumber("Gyro angle", CommandBase::driveSubS->Gyro->GetAngle());
	SmartDashboard::PutNumber("Acceleration X", CommandBase::driveSubS->Acceler->GetX());
	SmartDashboard::PutNumber("Acceleration Y", CommandBase::driveSubS->Acceler->GetY());

}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
