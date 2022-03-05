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

void printIrSensor(int LValue, int RValue);

int cntr = 1;

int main(void)
{
	if(wiringPiSetup() == -1)
		return 0;
	
	
	// ---- Ultrasonic

	// initUltrasonic();
 //    initDCMotor();
	
	// while(1)
	// {
        
	// dist = getDistance();
	

 //        if(dist <= 15){
 //            stopDCMotor();
 //            printf("STOP: distance is less than 15cm\n");
 //            delay(500);
	//     break;

 //        } else{
	// 	goForward();}
	// }

	// ---- IR ----
  
    int LValue, RValue, dist; 
    initIR();
    initUltrasonic();
	initSoftDCMotor();
	while (1) {
	    
	    LValue = digitalRead(LEFT_IR_PIN);
	    RValue = digitalRead(RIGHT_IR_PIN);
	    //~ printIrSensor(LValue, RValue);
	    
	    dist = getDistance();
	    
	   
	    if (dist <= 25) {
			stopDCMotor(100);
			//~ initDCMotor();
			smoothRight(1300);
			slow(300);
			
			stopDCMotor(100);
			smoothLeft(1100);
			slow(300);
			
			LValue = digitalRead(LEFT_IR_PIN);
			RValue = digitalRead(RIGHT_IR_PIN);
			printIrSensor(LValue, RValue);
			while(LValue == 0){
				LValue = digitalRead(LEFT_IR_PIN);
				RValue = digitalRead(RIGHT_IR_PIN);
				printIrSensor(LValue, RValue);
				goForward(0);
			}
			stopDCMotor(100);
			
			slow(200);
			initDCMotor();
			goRight(350);
			initSoftDCMotor();
			
			goForward(450);
		
			LValue = digitalRead(LEFT_IR_PIN);
			RValue = digitalRead(RIGHT_IR_PIN);		
			while(LValue == 1){
				LValue = digitalRead(LEFT_IR_PIN);
				RValue = digitalRead(RIGHT_IR_PIN);
				printIrSensor(LValue, RValue);
				//~ goForward(0);
			}
			slow(300);
			initDCMotor();
			goLeft(375);
			initSoftDCMotor();
			//~ slow(1000);
	    	stopDCMotor(100);
			
			printf("STOP\n");
			delay(500);
		break;
	    } else{
	    	goForward(0);
	    }

	   
	}
		
	return 0;
}

void printIrSensor(int LValue, int RValue){
	if(LValue == 1 && RValue == 0 ) {
		printf("Right\n");

	}else if (LValue == 0 && RValue == 1) { 
		printf("Left\n");

	} else if(LValue == 0 && RValue == 0){
		printf("Both\n");

	}else if(LValue == 1 && RValue == 1){
		printf("No\n");
	}
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
