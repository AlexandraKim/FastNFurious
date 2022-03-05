//gcc test.c -o test -lwiringPi
// Example 1
// 1. Forward/Backward
// 2. Point Turn Right/Left

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#include "dcmotor.h"
#include "ultrasonic.h"
#include "irsensor.h"
//~ void goRight(int ms);
//~ void initDCMotorSoft();
//~ void smoothLeft(int ms);
//~ void smoothRight(int ms);
//~ void slow(int ms);
//~ void stopDCMotor(int ms);


#define IN1_PIN		1
#define IN2_PIN		4
#define IN3_PIN		5
#define IN4_PIN		6

#define MAX_SPEED 50
#define MIN_SPEED 0

int cntr = 1;

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


//~ void initDCMotorSoft()
//~ {
	//~ pinMode(IN1_PIN,SOFT_PWM_OUTPUT);
	//~ pinMode(IN2_PIN,SOFT_PWM_OUTPUT);
	//~ pinMode(IN3_PIN,SOFT_PWM_OUTPUT);
	//~ pinMode(IN4_PIN,SOFT_PWM_OUTPUT);
	
	
	//~ softPwmCreate(IN1_PIN, MIN_SPEED, MAX_SPEED);
	//~ softPwmCreate(IN2_PIN, MIN_SPEED, MAX_SPEED);
	//~ softPwmCreate(IN3_PIN, MIN_SPEED, MAX_SPEED);
	//~ softPwmCreate(IN4_PIN, MIN_SPEED, MAX_SPEED);
//~ }
	
//~ void goRight(int ms)
//~ {
		//~ digitalWrite(IN1_PIN, HIGH);
		//~ digitalWrite(IN2_PIN, LOW);
		//~ digitalWrite(IN3_PIN, LOW);
		//~ digitalWrite(IN4_PIN, HIGH);		
		//~ delay(ms);	
//~ }	

//~ void smoothLeft(int ms)
//~ {
	//~ softPwmWrite(IN1_PIN, MAX_SPEED/64);
	//~ softPwmWrite(IN2_PIN, MIN_SPEED);
	//~ softPwmWrite(IN3_PIN, MAX_SPEED);
	//~ softPwmWrite(IN4_PIN, MIN_SPEED);
	//~ delay(ms);
//~ }

//~ void smoothRight(int ms)
//~ {
	//~ softPwmWrite(IN1_PIN, MAX_SPEED);
	//~ softPwmWrite(IN2_PIN, MIN_SPEED);
	//~ softPwmWrite(IN3_PIN, MAX_SPEED/64);
	//~ softPwmWrite(IN4_PIN, MIN_SPEED);
	//~ delay(ms);
//~ }
//~ void slow(int ms){
  	//~ softPwmWrite(IN1_PIN, 30);
	//~ softPwmWrite(IN2_PIN, MIN_SPEED);
	//~ softPwmWrite(IN3_PIN, 30);
	//~ softPwmWrite(IN4_PIN, MIN_SPEED);
	//~ delay(ms);
  
//~ }

//~ void stopDCMotor(int ms)
//~ {
	//~ softPwmWrite(IN1_PIN, MIN_SPEED);
	//~ softPwmWrite(IN2_PIN, MIN_SPEED);
	//~ softPwmWrite(IN3_PIN, MIN_SPEED);
	//~ softPwmWrite(IN4_PIN, MIN_SPEED);	
	//~ delay(ms);	
//~ //printf("Stop\n");
//~ }	
//gcc 1-motor_A.c -o motora -lwiringPi
// ./motora
