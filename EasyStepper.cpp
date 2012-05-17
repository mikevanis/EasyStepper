#include "Arduino.h"
#include "EasyStepper.h"

EasyStepper::EasyStepper(int dir, int step, int ms1, int ms2, int sleep) {
	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
	pinMode(ms1, OUTPUT);
	pinMode(ms2, OUTPUT);
	pinMode(sleep, OUTPUT);
}

void EasyStepper::setMaxSpeed(int maxSpeed) {
	_maxSpeed = maxSpeed;
}

void EasyStepper::setEasingAmount(int divider) {
	_easingDivider = divider;
}

void EasyStepper::setMicrostepping(int fraction) {
	MS1_MODE(fraction);
	MS2_MODE(fraction);
}

void EasyStepper::sleep() {
	digitalWrite(sleep, LOW);
}

int EasyStepper::MS1_MODE(int stepMode) {
	switch(stepMode) {
		case 1:
			stepMode = 0;
			break;
		case 2:
			stepMode = 1;
			break;
		case 4:
			stepMode = 0;
			break;
		case 8:
			stepMode = 1;
			break;
		}
		return stepMode;
	}
}

int EasyStepper::MS2_MODE(int stepMode) {
	switch(stepMode) {
		case 1:
			stepMode = 0;
			break;
		case 2:
			stepMode = 0;
			break;
		case 4:
			stepMode = 1;
			break;
		case 8:
			stepMode = 1;
			break;
		}
		return stepMode;
	}
}