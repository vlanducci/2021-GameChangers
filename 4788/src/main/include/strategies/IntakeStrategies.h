#pragma once
#include "Intake.h"

using Controllers = wml::controllers::SmartControllerGroup;

class IntakeManualStrategy : public wml::Strategy {
 public:
	IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup);
	void OnUpdate(double dt) override;

 private:
	Intake &_intake;
	Controllers &_contGroup;
};