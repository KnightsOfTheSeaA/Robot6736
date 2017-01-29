#ifndef ShootSubS_H
#define ShootSubS_H

//#include <WPILib.h>
#include <Spark.h>
#include <Commands/Subsystem.h>

class ShootSubS : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark* cannon;
	double SpeedLimitation = 1;

public:
	ShootSubS();
	void InitDefaultCommand();
	void setFireSpeed(double);
};

#endif  // ShootSubS_H
