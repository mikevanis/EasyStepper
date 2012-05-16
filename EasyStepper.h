/*
	EasyStepper.h - Library for the EasyStepper motor driver
	for Arduino
	
	www.mikevanis.com
	
	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifndef EasyStepper_h
#define EasyStepper_h

/******************
	Definitions
*******************/


class EasyStepper {
public:
	EasyStepper(int dir, int step, int ms1, int ms2, int sleep);
	void setMaxSpeed(long maxSpeed);
	void setSmoothing(int divider);
	void step(int number_of_steps);
	
private:
	int MS1_MODE(int stepMode);
	int MS2_MODE(int stepMode);
	
	int numOfSteps;
	int stepsRemaining;
	boolean antiClockwise;
	boolean microStepping;
	int minSpeed;
	int maxSpeed;
	int currentSpeed;
};

#endif