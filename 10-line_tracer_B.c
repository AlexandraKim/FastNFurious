
//Motor + Ultrasonic + Line Tracer

#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>
#include <softPwm.h>

#include "dcmotor.h"
#include "ultrasonic.h"

#define LEFT_TRACER_PIN 10
#define RIGHT_TRACER_PIN 11


#define IN1_PIN		1
#define IN2_PIN		4
#define IN3_PIN		5
#define IN4_PIN		6

#define TRIG_PIN		28
#define ECHO_PIN		29

void initLineTacer();

void lineTracerDetect();

int dist;
int leftTracer;
int rightTracer;
bool test1;

int main(void) {

    if (wiringPiSetup() == -1)
        return 0;

    initLineTacer();
    initUltrasonic();
    initSoftDCMotor();
    test1 = false;

    
    while (1) {

       slow(1500);
	
	//~ dist = getDistance();
	

        //~ if(dist <= 15){
            //~ stopDCMotor(100);
            //~ printf("STOP: distance is less than 15cm\n");
            //~ delay(1000);
	    

        //~ } else{
		//~ lineTracerDetect();
		
		//~ if(test1==true){
			
			break;
			//~ }
		//~ }
	
		
	}

    return 0;
}

void initLineTacer() {
    pinMode(LEFT_TRACER_PIN, INPUT);
    pinMode(RIGHT_TRACER_PIN, INPUT);
}



void lineTracerDetect(){
	
 leftTracer = digitalRead(LEFT_TRACER_PIN);
 rightTracer = digitalRead(RIGHT_TRACER_PIN);
	
	
	if (leftTracer == 0 && rightTracer == 1) {
		while(leftTracer == 0 && rightTracer == 1){
			printf("Right\n");
			smoothRight(300);
			leftTracer = digitalRead(LEFT_TRACER_PIN);
			rightTracer = digitalRead(RIGHT_TRACER_PIN);
		}
            


        }
        else if (rightTracer == 0 && leftTracer == 1) {
		while(rightTracer == 0 && leftTracer == 1){
			printf("Left\n");
			smoothLeft(300);
			leftTracer = digitalRead(LEFT_TRACER_PIN);
			rightTracer = digitalRead(RIGHT_TRACER_PIN);
		}
            


        }
        else if (rightTracer == 0 && leftTracer == 0) {
            printf("Stop\n");
			stopDCMotor(100);
			delay(1000);
			test1 = true;
			

        }
        else if (rightTracer == 1 && leftTracer == 1) {
            printf("Forward\n");
			slow(25);
					leftTracer = digitalRead(LEFT_TRACER_PIN);
		rightTracer = digitalRead(RIGHT_TRACER_PIN);

        }
	
	}

//gcc 10-line_tracer_B.c -o lineb -lwiringPi
// ./lineb
