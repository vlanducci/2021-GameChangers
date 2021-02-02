#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logiccd
void Robot::RobotInit() {
  ControlMap::InitsmartControllerGroup(robotMap.contGroup);

  
  // Drivebase Stuff

	//Create wml drivetrain
	drivetrain = new Drivetrain(robotMap.driveSystem.drivetrainConfig, robotMap.driveSystem.gainsVelocity);

	//Zero Encoders
	robotMap.driveSystem.drivetrain.GetConfig().leftDrive.encoder->ZeroEncoder();
	robotMap.driveSystem.drivetrain.GetConfig().rightDrive.encoder->ZeroEncoder();

	//Strategy controllers (Set default strategy for drivetrain to be Manual)
	drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
	drivetrain->StartLoop(100);

	//Inverts one side of our drivetrain
	drivetrain->GetConfig().rightDrive.transmission->SetInverted(true);
	drivetrain->GetConfig().leftDrive.transmission->SetInverted(false);

	//Register our systems to be called via strategy
	StrategyController::Register(drivetrain);
	NTProvider::Register(drivetrain);
}

void Robot::RobotPeriodic() {
  currentTimeStamp = frc::Timer::GetFPGATimestamp();
  dt = currentTimeStamp - lastTimeStamp;

  StrategyController::Update(dt);
  intake->update(dt);
  // NTProvider::Update();

  lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {
  Schedule(intake->GetDefaultStrategy(), true);
}
void Robot::TeleopPeriodic() {}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}