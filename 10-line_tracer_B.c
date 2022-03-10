
//Motor + Ultrasonic + Line Tracer

#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>
#include <softPwm.h>

#include "dcmotor.h"
#include "ultrasonic.h"
#include "irsensor.h"

#define LEFT_TRACER_PIN 10
#define RIGHT_TRACER_PIN 11


#define IN1_PIN		1
#define IN2_PIN		4
#define IN3_PIN		5
#define IN4_PIN		6

#define TRIG_PIN		28
#define ECHO_PIN		29
//~ low battery
int turn = 350;
int slowDelay = 25;

//~ full battery
//~ int turn = 300;
//~ int slowDelay = 10;

void initLineTacer();

void lineTracerDetect();
void avoidObstacle();

int dist;
int leftTracer;
int rightTracer;
int LValue, RValue; 
bool test1;
int obstaclesCount;

int main(void) {

    if (wiringPiSetup() == -1)
        return 0;
    initIR();
    initLineTacer();
    initUltrasonic();
    initSoftDCMotor();
    test1 = false;
    
    //~ slow(250);
    //~ smoothRight(300);
    //~ stopDCMotor(100);

    
    while (1) {

       //~ slow(1500);
	
	dist = getDistance();
	

        if(dist <= 15){
		
            stopDCMotor(100);
            printf("STOP: distance is less than 15cm\n");
            delay(1000);
	    obstaclesCount++;
		//~ if(obstaclesCount == 2){
			avoidObstacle();
		//~ }
	    //~ stopDCMotor(100);
	    //~ break;
	    

        } else{
		lineTracerDetect();
		
		if(test1==true){
			
			break;
			}
		}
	
		
	}
	stopDCMotor(100);

    return 0;
}
void avoidObstacle(){
	LValue = digitalRead(LEFT_IR_PIN);
	RValue = digitalRead(RIGHT_IR_PIN);
	while (LValue == 0) {

		
		
	    printf("Left\n");
	    smoothRight(10);

		//~ }
		//~ else if(LValue == 0 && RValue == 0){
		    //~ printf("Both\n");

		//~ }else if(LValue == 1 && RValue == 1){
		    //~ printf("No\n");
		//~ }
		LValue = digitalRead(LEFT_IR_PIN);
		RValue = digitalRead(RIGHT_IR_PIN);
	}
	
	leftTracer = digitalRead(LEFT_TRACER_PIN);
	rightTracer = digitalRead(RIGHT_TRACER_PIN);
	while(rightTracer == 1){
		slow(20);
		
	leftTracer = digitalRead(LEFT_TRACER_PIN);
	rightTracer = digitalRead(RIGHT_TRACER_PIN);
		}
	
	stopDCMotor(100);
	smoothLeft(1000);
	slow(600);
	smoothLeft(300);
	stopDCMotor(100);
	//~ test1 = true;
	
	//~ low battery
	//~ goRight(800);
	//~ stopDCMotor(100);
	//~ goForward(625);
	//~ // 
	//~ goLeft(750);
	//~ stopDCMotor(100);
	//~ goForward(1700);
	//~ stopDCMotor(100);
	//~ goLeft(900);
	//~ stopDCMotor(100);
	//~ goForward(500);
	//~ stopDCMotor(100);
	//~ goRight(900);
	//~ stopDCMotor(100);
	
	
	//~ full battery
	//~ smoothRight(1000);
	//~ // 
	//~ smoothLeft(2000);
	//~ slow(80);
	//~ smoothLeft(2000);
	//~ slow(150);
	//~ smoothRight(1600);
	
}
void initLineTacer() {
    pinMode(LEFT_TRACER_PIN, INPUT);
    pinMode(RIGHT_TRACER_PIN, INPUT);
}



void lineTracerDetect(int dist){
	
	 leftTracer = digitalRead(LEFT_TRACER_PIN);
	 rightTracer = digitalRead(RIGHT_TRACER_PIN);
	
	
	if (leftTracer == 0 && rightTracer == 1) {
		printf("Right\n");
		
		stopDCMotor(100); 
		smoothRight(turn);
		stopDCMotor(100); 
		//~ test1 = true;


        }
        else if (rightTracer == 0 && leftTracer == 1) {
		printf("Left\n");
		stopDCMotor(100);
		smoothLeft(turn);
		stopDCMotor(100); 
		


        }
        else if (rightTracer == 0 && leftTracer == 0) {
		printf("Stop\n");
		stopDCMotor(100);
		delay(1000);

		test1 = true;
			

        }
        else if (rightTracer == 1 && leftTracer == 1) {
            printf("Forward\n");
		slow(slowDelay);
		

        }
	
	}

//gcc 10-line_tracer_B.c -o lineb -lwiringPi
// ./lineb
