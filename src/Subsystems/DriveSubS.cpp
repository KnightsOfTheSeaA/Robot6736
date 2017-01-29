#include "DriveSubS.h"
#include "../RobotMap.h"
#include "Commands/Drive.h"

#include <AnalogGyro.h>
#include <RobotDrive.h>
#include <SPI.h>
#include <ADXRS450_Gyro.h>
#include <BuiltInAccelerometer.h>

DriveSubS::DriveSubS() : Subsystem("ExampleSubsystem") {
	// Driving motor initializations
	//leftMotor = new Spark(LEFT_MOTOR);
	//frc::RobotDrive robotDrive { 0, 1 };
	robotDrive = new RobotDrive(LEFT_MOTOR, RIGHT_MOTOR); 	// robot drive system

	// Sensors
	//frc::AnalogGyro gyro;
	static const float kP = 0.03;

	Gyro = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);
	Gyro->Reset();
	Acceler = new BuiltInAccelerometer(BuiltInAccelerometer::Range::kRange_4G);
}


void DriveSubS::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveSubS::RotateAngle(float Angle){

	CommandBase::driveSubS->robotDrive->SetLeftRightMotorOutputs();
	CommandBase::driveSubS->Gyro->GetAngle());


}
