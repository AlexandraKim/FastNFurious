#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>
#include <softPwm.h>

#include "services/initServices.h"


//~ low battery
//~ int turn = 350;
//~ int slowDelay = 25;

//~ full battery
int turn = 375;
int slowDelay = 5;

void run();
void runLineTracerDetection();
void avoidObstacle();
bool isObstacleDetected();
void stopBeforeObstacle();
void park();

bool quit;
int obstaclesCount = 0;

int turnStartTime=0;
int turnEndTime=0;
        

int main(void) {

    if (wiringPiSetup() == -1) {
        return 0;
    }

    InitServices();
    quit = false;
    delay(100);
    //~ LineTracerTest();
    //~ UltrasonicTest();
    
    run();
    
    stopDCMotor(100);

    return 0;
}

void run() {
     while (1) {
        if(distance <= 25 && distance > 0) {
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
                
                park();
                obstaclesCount++;
                printf("park count %d\n", obstaclesCount);
            } else if(obstaclesCount == 3) {
                stopDCMotor(100);
                break; 
            }
        } else{
            runLineTracerDetection();
        //~ printf("general count %d\n", obstaclesCount);
            if(quit == true) {
                break;
            }
        }
    }
}

void stopBeforeObstacle(){
    while (distance <= 25) {
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
    //~ if(rightTracer == 1){
       //~ runLineTracerDetection();  
       
    //~ }
    while(leftTracer == 1){
        runLineTracerDetection();    
    }
    goBackward(600);
    stopDCMotor(1);
    goLeft(500);
    bool backwardRight = false;
    //~ while(leftTracer == 1){
        goForward(500);
        goRight(300);
        //~ if(rightTracer == 1){
            //~ smoothBackRight(300);
            //~ backwardRight = true;
            //~ break;
        //~ }
    //~ }
    //~ if (!backwardRight){
        //~ goRight(500);
    //~ }
    
    runLineTracerDetection();  
    //~ our
    //~ stopDCMotor(100);
    //~ while (LValue == 0) {
        //~ printf("Left Obstacle\n");
        //~ goRight(20);
    //~ }
    //~ while(rightTracer == 1){
        //~ slow(20);
    //~ }
    
    //~ goForward(200);
    //~ goLeft(500);
    //~ goForward(500);
    //~ goLeft(500);
    //~ goForward(1000);
    //~ goRight(800);
}

void park(){
    printf("Park \n");
    stopDCMotor(100);
    while(RValue == 0){
        goLeft(20);
    }
    //~ while(rightTracer == 1){
        //~ runLineTracerDetection();    
    //~ }
    //~ while
    
    //~ stopDCMotor(100);
    //~ quit = true;
    
    while(distance > 15){
        printf("dist %d\n", distance);
        if(rightTracer == 0){
                goLeft(20);
        } else {
                goForward(0);
        }
    }
    
    stopDCMotor(100);
}

void runLineTracerDetection(){
    if (leftTracer == 0 && rightTracer == 1) {
        printf("Turn right\n");
        
        goRight(20);
    } else if (rightTracer == 0 && leftTracer == 1) {
        printf("Turn left\n");

        goLeft(20);
    } else if (rightTracer == 0 && leftTracer == 0) {
        //~ printf("Stop\n");
        //~ stopDCMotor(100);
        //~ delay(1000);

        //~ quit = true;
    } else if (rightTracer == 1 && leftTracer == 1) {
        goForward(0);
    }
}

//gcc program.c -o program -lwiringPi
// ./lineb
