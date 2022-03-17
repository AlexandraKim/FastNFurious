#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>
#include <softPwm.h>

#include "services/initServices.h"

int turnDelay = 20;

void run();
void stopBeforeObstacle();
void avoidObstacle();
void runLineTracerDetection();

bool quit = false;
int obstaclesCount = 0;
int distanceBeforeObject = 25;

int main(void) {
    if (wiringPiSetup() == -1) {
        return 0;
    }

    InitServices();
    delay(100);
    
    run();
    
    stopDCMotor(100);

    return 0;
}

void run() {
    while (1) {
        if(Distance <= distanceBeforeObject && Distance > 0) {
            if(obstaclesCount == 0) {
                stopBeforeObstacle();
                obstaclesCount++;
                runLineTracerDetection();
            } else if(obstaclesCount == 1) {
                avoidObstacle();
                obstaclesCount++;
                printf("avoid count %d\n", obstaclesCount);
                runLineTracerDetection();
            } else if (obstaclesCount == 2) {
                stopDCMotor(100);
                break; 
            }
        } else{
            runLineTracerDetection();
            if(quit == true) {
                break;
            }
        }
    }
}

void stopBeforeObstacle(){
    while (Distance <= distanceBeforeObject) {
        stopDCMotor(1);
        printf("STOP: distance is less than 15cm %d\n", distance);
        delay(5);
    }
}

void avoidObstacle(){
    stopDCMotor(1);
    while (LValue == 0) {
        printf("Left Obstacle\n");
        goRight(30);
    }
    while(LeftTracer == 1) {
        runLineTracerDetection();    
    }
    goBackward(600);
    stopDCMotor(1);
    goLeft(500);
    goForward(500);
    goRight(300);
    runLineTracerDetection();  
}

void runLineTracerDetection(){
    if (LeftTracer == 0 && RightTracer == 1) {
        printf("Turn right\n");
        
        goRight(turnDelay);
    } else if (RightTracer == 0 && LeftTracer == 1) {
        printf("Turn left\n");

        goLeft(turnDelay);
    } else if (RightTracer == 0 && LeftTracer == 0) {
        printf("Stop\n");
        stopDCMotor(100);
        delay(1000);

        quit = true;
    } else if (RightTracer == 1 && LeftTracer == 1) {
        goForward(0);
    }
}