#ifndef DriveSubS_H
#define DriveSubS_H

#include <Commands/Subsystem.h>
#include <RobotDrive.h>
#include <ADXRS450_Gyro.h>
#include <BuiltInAccelerometer.h>
#include <Encoder.h>

#define WHEELDIAMETER 100 // Wheel diameter in mm
#define ENCODERDIVITION 20 // Set encoder divition

class DriveSubS : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	//ADXRS450_Gyro Gyro;

	long Distance[2];


public:
	RobotDrive* robotDrive;
	ADXRS450_Gyro* Gyro;
	BuiltInAccelerometer* Acceler;
	Encoder* Encoder0;
	Encoder* Encoder1;
	DriveSubS();
	void InitDefaultCommand();
	void RotateAngle(float Angle, double Speed);
	void DriveDistance(long UDistance, short Direction, double Speed);
};

#endif  // DriveSubS_H
