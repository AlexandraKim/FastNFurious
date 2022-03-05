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
#include "line_tracer.h"

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

	while (1) {

       
	
		dist = getDistance();
	

        if(dist <= 15){
            stopDCMotor();
            printf("STOP: distance is less than 15cm\n");
            delay(1000);
	    

        } else{
		lineTracerDetect();
		
		if(test1==true){
			
			break;}
		}
	
		
	}
	return 0;
}


//~ void mission1(int LValue, int RValue){

    //~ if(LValue == 1 && RValue == 0 ) {
        //~ printf("Right\n");
        //~ goRight();
        //~ delay(600);
       
    //~ }else if (LValue == 0 && RValue == 1) { 
        //~ printf("Left\n");
        //~ goLeft();
        //~ delay(600);

    //~ }else if(LValue == 0 && RValue == 0){
        //~ printf("Stop\n");
        //~ stopDCMotor();
        //~ delay(600);

    //~ }else if(LValue == 1 && RValue == 1){
        //~ printf("Forward\n");
        //~ goForward();
        //~ delay(500);
    //~ }

//~ }

//gcc 1-motor_A.c -o motora -lwiringPi
// ./motora
