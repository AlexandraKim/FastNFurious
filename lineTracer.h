#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>

#define LEFT_TRACER_PIN 10
#define RIGHT_TRACER_PIN 11



void initLineTacer();
void lineTracerDetect();

void initLineTacer() {
    pinMode(LEFT_TRACER_PIN, INPUT);
    pinMode(RIGHT_TRACER_PIN, INPUT);
}

// void lineTracerDetect(){
//     if (leftTracer == 0 && rightTracer == 1) {
//         printf("Right\n");
//         goRight();
//         delay(500);

//     } else if (rightTracer == 0 && leftTracer == 1) {
//         printf("Left\n");
//         goLeft();
//         delay(500);
//     } else if (rightTracer == 0 && leftTracer == 0) {
//         printf("Stop\n");
//         stopDCMotor();
//         delay(1000);
//         test1 = true;
        

//     }
//     else if (rightTracer == 1 && leftTracer == 1) {
//         printf("Forward\n");
//         goForward();
//         delay(500);

//     }
// }

PI_THREAD(lineTracerThread) {
	initLineTacer();
    while(1) {
        leftTracer = digitalRead(LEFT_TRACER_PIN);
        rightTracer = digitalRead(RIGHT_TRACER_PIN);
    }
    
}

void LineTracerThread();

void LineTracerThread() {
    if(piThreadCreate(lineTracerThread) != 0) {
        printf("Line Tracer not initialized\n");
    }
}
