#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>
#include <softPwm.h>

#include "services/initServices.h"


//~ low battery
//~ int turn = 350;
//~ int slowDelay = 25;

//~ full battery
int turn = 500;
int slowDelay = 5;

void lineTracerDetect();
void avoidObstacle();
void park();

bool quit;
int obstaclesCount = 0;

int main(void) {

    if (wiringPiSetup() == -1) {
        return 0;
    }

    InitServices();
    
    quit = false;
    
    while (1) {
       
        if(distance <= 15) {
            if(obstaclesCount == 0){
                while (distance <= 15) {
                
                stopDCMotor(1);
                printf("STOP: distance is less than 15cm\n");
                //~ delay(10);
                }
                obstaclesCount++;
                lineTracerDetect();
            }
            
            
            
            if(obstaclesCount == 2){
                avoidObstacle();
                obstaclesCount++;
            } else if (obstaclesCount == 3){
                park();
            } else if(obstaclesCount == 4) {
                quit = true;    
            }
        } else{
            lineTracerDetect();
        
            if(quit == true) {
                break;
            }
        }
    }
    stopDCMotor(100);

    return 0;
}

void avoidObstacle(){
    while (LValue == 0) {
        printf("Left Obstacle\n");
        smoothRight(13);
    }
    while(rightTracer == 1){
        slow(10);
    }
    
    stopDCMotor(100);
    smoothLeft(1500);
    slow(900);
    smoothLeft(300);
    stopDCMotor(100);
    smoothRight(800);
    slow(600);
    //~ quit = true;
    
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

void park(){
    goLeft(500);
    quit = true;
    
    //~ while(dist > 15){
        //~ slow(slowDelay);
    //~ }
    stopDCMotor(100);
}

void lineTracerDetect(){
    
    if (leftTracer == 0 && rightTracer == 1) {
        printf("Turn right\n");
        
        stopDCMotor(100); 
        smoothRight(turn);
        //~ stopDCMotor(100);
    } else if (rightTracer == 0 && leftTracer == 1) {
        printf("Turn left\n");

        stopDCMotor(100);
        smoothLeft(turn);
        //~ stopDCMotor(100); 
    } else if (rightTracer == 0 && leftTracer == 0) {
        printf("Stop\n");
        stopDCMotor(100);
        delay(1000);

        quit = true;
    
    } else if (rightTracer == 1 && leftTracer == 1) {
        slow(slowDelay);
    }
}

//gcc program.c -o program -lwiringPi
// ./lineb
