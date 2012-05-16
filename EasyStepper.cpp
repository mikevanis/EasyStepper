#include "Arduino.h"
#include "EasyStepper.h"

EasyStepper::EasyStepper(int dir, int step, int ms1, int ms2, int sleep) {
	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
	pinMode(ms1, OUTPUT);
	pinMode(ms2, OUTPUT);
	pinMode(sleep, OUTPUT);
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