#pragma once
#include "RobotMap.h"

enum IntakeState {
	ON,
  OFF
};

class Intake : public wml::StrategySystem {
 public:
	Intake(wml::TalonSrx &IntakeMotor);
	void setIntake(const IntakeState st, double intakePower = 0);
	void updateIntake(double dt);
	void update(double dt);

 private:
	wml::TalonSrx &_intakeMotor;
	IntakeState _intakeState{ IntakeState::OFF };
	double _intakePower = 0;

	frc:: Timer _timer;
};