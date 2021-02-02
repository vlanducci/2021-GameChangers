#pragma once

/**
 * Local files (strategies/)
 */ 
#include "strategies/IntakeStrategies.h"
#include "strategies/DriveSystem.h"

class Robot : public frc::TimedRobot, protected wml::StrategyController, protected wml::NTProvider {
 public:
	void RobotInit() override;
	void RobotPeriodic() override;

	void DisabledInit() override;
	void DisabledPeriodic() override;

	void AutonomousInit() override;
	void AutonomousPeriodic() override;

	void TeleopInit() override;
	void TeleopPeriodic() override;

	void TestInit() override;
	void TestPeriodic() override;

 private:
	// Istances
	RobotMap robotMap;
	Intake *intake;
	wml::Drivetrain *drivetrain; // WML drivetrain (Not local)
};