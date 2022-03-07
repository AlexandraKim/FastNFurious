#include <stdio.h>
#include <wiringPi.h>

#define LEFT_IR_PIN 27
#define RIGHT_IR_PIN 26

void initIR();

void initIR()
{
    pinMode(LEFT_IR_PIN, INPUT);
    pinMode(RIGHT_IR_PIN, INPUT);
		
}
