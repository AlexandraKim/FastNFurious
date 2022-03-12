#include <stdio.h>
#include <wiringPi.h>

#define LEFT_IR_PIN 27
#define RIGHT_IR_PIN 16

void InitIR();
void IrThread();

void InitIR()
{
    pinMode(LEFT_IR_PIN, INPUT);
    pinMode(RIGHT_IR_PIN, INPUT);
		
}

PI_THREAD(irThread) {
    InitIR();
    while(1) {
        LValue = digitalRead(LEFT_IR_PIN);
        RValue = digitalRead(RIGHT_IR_PIN);
    }
    
}



void IrThread() {
    if(piThreadCreate(irThread) != 0) {
        printf("IR sensor not initialized\n");
    }
}


void IrTest(){
    while(1){
	

     if(LValue == 1 && RValue == 0 ) {
	printf("Right\n");
       
    }else if (LValue == 0 && RValue == 1) { 
	printf("Left\n");

    }else if(LValue == 0 && RValue == 0){
	printf("Both\n");

    }else if(LValue == 1 && RValue == 1){
	printf("No\n");
    }
}
}

