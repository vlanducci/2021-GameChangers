#include "Intake.h"

using namespace wml;
using namespace wml::controllers;

Intake::Intake(wml::TalonSrx &IntakeMotor) : _intakeMotor(IntakeMotor) {}

void Intake::setIntake(const IntakeState st, double intakePower) {
  _intakeState = st;
	_intakePower = intakePower;
}

void Intake::updateIntake(double dt) {
	double intakeVoltage = 0;

	switch(_intakeState) {
		case IntakeState::OFF:
			intakeVoltage = 0;
			break;
		
		case IntakeState::ON:
			intakeVoltage = 12* _intakePower;
	}
	_intakeMotor.Set(intakeVoltage);
}

void Intake::update(double dt) {
	updateIntake(dt);
}

