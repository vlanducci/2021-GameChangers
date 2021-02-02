#include "strategies/IntakeStrategies.h"

IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
  Requires(&intake);
	SetCanBeInterrupted(true);
	SetCanBeReused(true);
}

void IntakeManualStrategy::OnUpdate(double dt) {
	double powerIn = fabs(_contGroup.Get(ControlMap::IntakeOutake)) >= ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::IntakeOutake) : 0;
	double powerOut = fabs(_contGroup.Get(ControlMap::IntakeOutake)) <= ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::IntakeOutake) : 0;

	if (_contGroup.Get(ControlMap::IntakeOutake) >= ControlMap::TriggerDeadzone) {
		_intake.setIntake(IntakeState::ON, 0.6);
	} else {
		_intake.setIntake(IntakeState::OFF, 0);
	}
}