#include "DriveSubS.h"
#include "../RobotMap.h"
#include "Commands/Drive.h"

#include <AnalogGyro.h>
#include <RobotDrive.h>
#include <SPI.h>
#include <ADXRS450_Gyro.h>
#include <BuiltInAccelerometer.h>
#include <Encoder.h>


DriveSubS::DriveSubS() : Subsystem("ExampleSubsystem")
{
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

	//Encoder0 = new Encoder()
	Encoder0 = new Encoder(0, 1, false); // Init right motor encoder
	Encoder1 = new Encoder(2, 4, false); // Init left motor encoder

	Encoder0->SetDistancePerPulse(WHEELDIAMETER/ENCODERDIVITION);


}


void DriveSubS::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveSubS::RotateAngle(float Angle, double Speed)
{

	int DAngle= CommandBase::driveSubS->Gyro->GetAngle() + Angle;

	short D = abs(DAngle) / DAngle;

	while(CommandBase::driveSubS->Gyro->GetAngle() > DAngle + 2 || 	CommandBase::driveSubS->Gyro->GetAngle() < DAngle - 2 )
	{


		CommandBase::driveSubS->robotDrive->SetLeftRightMotorOutputs(Speed*D,Speed*D);

	}

	CommandBase::driveSubS->Gyro->GetAngle();


}

void DriveSubS::DriveDistance(long UDistance, short Direction, double Speed){


	//Distance[0] = CommandBase::driveSubS->Encoder0->GetDistance();
	//Distance[1] = CommandBase::driveSubS->Encoder1->GetDistance();
	CommandBase::driveSubS->Encoder0->Reset();
	CommandBase::driveSubS->Encoder1->Reset();

	while(UDistance <= CommandBase::driveSubS->Encoder1->GetDistance()){

	switch(Direction){

		case 0:CommandBase::driveSubS->robotDrive->SetLeftRightMotorOutputs(Speed, -Speed);break;
		case 1:CommandBase::driveSubS->robotDrive->SetLeftRightMotorOutputs(-Speed, Speed);break;

	}

	}

}
