#include <stdio.h>
#include <wiringPi.h>

#define TRIG_PIN		28
#define ECHO_PIN		29

void InitUltrasonic();
void UltrasonicThread();
void UltrasonicTest();

void InitUltrasonic(){
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

}


PI_THREAD(ultrasonicThread) {
	InitUltrasonic();
    while(1) {
        digitalWrite(TRIG_PIN, LOW) ;
        delay(500) ;
        digitalWrite(TRIG_PIN, HIGH) ;
        
        delayMicroseconds(10) ;
        digitalWrite(TRIG_PIN, LOW) ;
        
        int 	start_time=0;
        int end_time=0;
        while (digitalRead(ECHO_PIN) == 0) {
            start_time = micros() ;
            }
        
        
        while (digitalRead(ECHO_PIN) == 1) {
            end_time = micros() ;
            }
        
        
        distance = (int)((end_time - start_time) / 29. / 2.) ;
    }
    
}

void UltrasonicThread() {
    if(piThreadCreate(ultrasonicThread) != 0) {
        printf("Ultrasonic sensor not initialized\n");
    }
}

void UltrasonicTest(){
        while(1)
	{
		     printf("Distance %dcm\n", distance);
	         delay(100);	
	}
}

