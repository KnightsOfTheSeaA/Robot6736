#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/ShootSubS.h"
#include "Subsystems/DriveSubS.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void init();
	// Create a single static instance of all of your subsystems
	static ExampleSubsystem *exampleSubsystem;
	static ShootSubS *shootSubS;
	static DriveSubS *driveSubS;
	static OI *oi;
	//static std::unique_ptr<ExampleSubsystem> exampleSubsystem;
	//static std::unique_ptr<ShootSubS> shootSubS;
	//static std::unique_ptr<OI> oi;
};

#endif  // COMMAND_BASE_H
