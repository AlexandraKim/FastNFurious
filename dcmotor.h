#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define IN1_PIN		1
#define IN2_PIN		4
#define IN3_PIN		5
#define IN4_PIN		6
#define ENA_PIN		23
#define ENB_PIN		26

#define MAX_SPEED 50
#define MIN_SPEED 0
#define SPEED_COEFFICIENT 8

//~ low battery
#define SLOW_SPEED 30
//~ full battery
//~ #define SLOW_SPEED 25


void initSoftDCMotor();
void goForward(int ms);
void goBackward(int ms);
void smoothLeft(int ms);
void goLeft(int ms);
void smoothRight(int ms);
void goRight(int ms);
void stopDCMotor(int ms);
void slow(int ms);
void smoothBackLeft(int ms);

void initSoftDCMotor()
{
	pinMode(IN1_PIN,SOFT_PWM_OUTPUT);
	pinMode(IN2_PIN,SOFT_PWM_OUTPUT);
	pinMode(IN3_PIN,SOFT_PWM_OUTPUT);
	pinMode(IN4_PIN,SOFT_PWM_OUTPUT);
	 
	softPwmCreate(IN1_PIN, MIN_SPEED, MAX_SPEED);
	softPwmCreate(IN2_PIN, MIN_SPEED, MAX_SPEED);
	softPwmCreate(IN3_PIN, MIN_SPEED, MAX_SPEED);
	softPwmCreate(IN4_PIN, MIN_SPEED, MAX_SPEED);
}

void slow(int ms){
  	softPwmWrite(IN1_PIN, SLOW_SPEED+6);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, SLOW_SPEED);
	softPwmWrite(IN4_PIN, MIN_SPEED);
	delay(ms);
}

void goForward(int ms)
{	
	softPwmWrite(IN1_PIN, MAX_SPEED);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, MAX_SPEED);
	softPwmWrite(IN4_PIN, MIN_SPEED);
	delay(ms);
}

void goBackward(int ms)	
{
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, MAX_SPEED);
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, MAX_SPEED);
	delay(ms);
}
	
	
void smoothLeft(int ms)
{
	softPwmWrite(IN1_PIN, MAX_SPEED/SPEED_COEFFICIENT);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, MAX_SPEED);
	softPwmWrite(IN4_PIN, MIN_SPEED);
	delay(ms);
}
	
void goLeft(int ms)
{
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, MAX_SPEED);
	softPwmWrite(IN3_PIN, MAX_SPEED);
	softPwmWrite(IN4_PIN, MIN_SPEED);
	delay(ms);
}

void smoothRight(int ms)
{
	//~ +6
	softPwmWrite(IN1_PIN, MAX_SPEED);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, MAX_SPEED/SPEED_COEFFICIENT);
	softPwmWrite(IN4_PIN, MIN_SPEED);
	delay(ms);
}

void goRight(int ms)
{
	softPwmWrite(IN1_PIN, MAX_SPEED);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, MAX_SPEED);
	delay(ms);
}

void smoothBackLeft(int ms){
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, MAX_SPEED/SPEED_COEFFICIENT); 
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, MAX_SPEED);
	delay(ms);
}

void smoothBackRight(int ms){
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, MAX_SPEED); 
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, MAX_SPEED/SPEED_COEFFICIENT);
	delay(ms);
}

void stopDCMotor(int ms)
{
	softPwmWrite(IN1_PIN, MIN_SPEED);
	softPwmWrite(IN2_PIN, MIN_SPEED);
	softPwmWrite(IN3_PIN, MIN_SPEED);
	softPwmWrite(IN4_PIN, MIN_SPEED);	
	delay(ms);	
	printf("stopDCMotor\n");
}	
