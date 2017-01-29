#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/ShootSubS.h"
#include "Subsystems/DriveSubS.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
//		std::make_unique<ExampleSubsystem>();
//std::unique_ptr<ShootSubS> CommandBase::shootSubS =
//		std::make_unique<ShootSubS>();

ExampleSubsystem* CommandBase::exampleSubsystem = NULL;
ShootSubS* CommandBase::shootSubS = NULL;
DriveSubS* CommandBase::driveSubS = NULL;


//std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

OI* CommandBase::oi = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init(){
	CommandBase::exampleSubsystem = new ExampleSubsystem();
	CommandBase::shootSubS = new ShootSubS();
	CommandBase::driveSubS = new DriveSubS();
	oi = new OI();
}
