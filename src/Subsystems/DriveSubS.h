#ifndef DriveSubS_H
#define DriveSubS_H

#include <Commands/Subsystem.h>
#include <RobotDrive.h>
#include <ADXRS450_Gyro.h>
#include <BuiltInAccelerometer.h>
#include <Encoder.h>

class DriveSubS : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	//ADXRS450_Gyro Gyro;

<<<<<<< HEAD
	//long Distance[2];


=======
>>>>>>> parent of 45e3230... angle and distance function for navigation
public:
	RobotDrive* robotDrive;
	ADXRS450_Gyro* Gyro;
	BuiltInAccelerometer* Acceler;
	DriveSubS();
	void InitDefaultCommand();
	void RotateAngle(float Angle);
};

#endif  // DriveSubS_H
