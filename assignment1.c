#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#include "dcmotor.h"
#include "ultrasonic.h"
#include "irsensor.h"
#include "line_tracer.h"

#define IN1_PIN		1
#define IN2_PIN		4
#define IN3_PIN		5
#define IN4_PIN		6

int cntr = 1;

//~ Sorry for the hard code, we'll do our best next time
int main(void)
{
	if(wiringPiSetup() == -1)
		return 0;

	int dist;
	initUltrasonic();
	initSoftDCMotor();

	// 1st step
	dist = getDistance();
	while (dist >= 25) {
		slow(100);
	    dist = getDistance();
	}

	stopDCMotor(1);
	smoothRight(1200);
	stopDCMotor(1);
	slow(1300);
	stopDCMotor(1);
	smoothLeft(1200);
	stopDCMotor(1);

	// 2nd step
	dist = getDistance();
	while (dist >= 25) {
		slow(100);
	    dist = getDistance();
	}

	stopDCMotor(1);
	smoothRight(1200);
	stopDCMotor(1);
	slow(300);
	stopDCMotor(1);
	smoothLeft(1250);
	slow(3000);
	stopDCMotor(1);
	smoothLeft(1250);
	stopDCMotor(100);

	// 3rd step
	dist = getDistance();
	while (dist >= 25) {
		slow(100);
	    dist = getDistance();
	}

	stopDCMotor(1);
	smoothRight(1200);
	stopDCMotor(1);
	slow(400);
	stopDCMotor(1);
	smoothLeft(1200);
	slow(2500);
	stopDCMotor(1);
	smoothLeft(1200);
	stopDCMotor(100);


	// 4th step
	dist = getDistance();
	while (dist >= 25) {
		slow(100);
	    dist = getDistance();
	}

	stopDCMotor(1);
	smoothRight(1200);
	stopDCMotor(1);
	slow(400);
	stopDCMotor(1);
	smoothLeft(1200);
	slow(3500);
	stopDCMotor(1);
	smoothLeft(1200);
	stopDCMotor(100);


	// 5th step
	dist = getDistance();
	while (dist >= 25) {
		slow(100);
	    dist = getDistance();
	}

	stopDCMotor(1);
	smoothRight(1200);
	stopDCMotor(1);
	slow(1000);
	stopDCMotor(1);
	smoothLeft(1200);
	stopDCMotor(1);
	smoothRight(1200);
	stopDCMotor(1);
	slow(1200);
	stopDCMotor(1);
	delay(150);	
	return 0;
}
