#include "Arduino.h"
#include "EasyStepper.h"

#define TRUE 1
#define FALSE 0
typedef int boolean;

EasyStepper::EasyStepper(int dir, int step, int ms1, int ms2, int sleep) {
	pinMode(dir, OUTPUT);
	pinMode(step, OUTPUT);
	pinMode(ms1, OUTPUT);
	pinMode(ms2, OUTPUT);
	pinMode(sleep, OUTPUT);
	_easingDivider = 3;
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

void EasyStepper::step(int numOfSteps) {
	if((unsigned long)(micros() - previous_timer) >= 500) {
		previous_timer = micros();
		
		// Run motor
		if(stepsRemaining > 0) {
			// Is it time to microstep yet?
			if(stepsRemaining == numOfSteps/_easingDivider && !microstepping) {
				stepsRemaining *= 8;
				digitalWrite(ms1, MS1_MODE(8));
				digitalWrite(ms2, MS2_MODE(8));
				microstepping = true;
			}
			else if(stepsRemaining > numOfSteps/_easingDivider) {
				if((timer+1) % _maxSpeed == 0) {
					digitalWrite(step, LOW);
					digitalWrite(step, HIGH);
					stepsRemaining--;
				}
			}
			else {
				if((timer+1) % (currentSpeed/8) == 0) {
					digitalWrite(step, LOW);
					digitalWrite(step, HIGH);
					stepsRemaining--;
					currentSpeed = map(stepsRemaining, numOfSteps/_easingDivider, 1, maxSpeed, minSpeed);
				}
			}
		}
	}
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