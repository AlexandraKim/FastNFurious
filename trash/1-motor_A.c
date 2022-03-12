
// Example 1
// 1. Forward/Backward
// 2. Point Turn Right/Left

#include <stdio.h>
#include <wiringPi.h>

#define IN1_PIN		1
#define IN2_PIN		4
#define IN3_PIN		5
#define IN4_PIN		6
#define ENA_PIN		23
#define ENB_PIN		24


void initDCMotor();
void goForward();
void goBackward();
void goLeft();
void goRight();
void stopDCMotor();

int cntr = 1;

int main(void)
{
	if(wiringPiSetup() == -1)
		return 0;
	
	
	
	initDCMotor();
	
	//~ pinMode(ENA_PIN, PWM_OUTPUT);
	//~ pinMode(ENB_PIN, PWM_OUTPUT);
	//put PWM in mark-space mode, which will give you 
	//the traditional (and easily predictable) PWM   
	pwmSetMode(PWM_MODE_MS);
	//Set clock divisor to 4000
    pwmSetClock(8);
    pwmSetRange(128);
	
	while(cntr>0)
	{
		   goForward();
		   //~ delay(1000); //1 sec
		   		printf("Start\n");
		   for(int i = 0; i < 1024; ++i){
			   pwmWrite (ENA_PIN, i);
			   pwmWrite (ENB_PIN, i);
			   printf("Start %d\n", i);
			   //~ analogWrite(ENA_PIN, i);
				//~ analogWrite(ENB_PIN, i);
				delay(1);
			}
				printf("del\n");
			//~ delay(1000);
					printf("Reverse\n");
			 for(int i = 255; i > 0; i--){
				 pwmWrite (ENA_PIN, i);
				pwmWrite (ENB_PIN, i);
			   //~ analogWrite(ENA_PIN, i);
				//~ analogWrite(ENB_PIN, i);
				delay(20);
			}
          
		   stopDCMotor();
	       delay(500);
		 
	  //   	goBackward();
	  //       delay(500);
			
			// stopDCMotor();
			// delay(500);

			// goRight();
			// delay(500);

	  //       goLeft();
	  //       delay(500);
	        
	  //       stopDCMotor();
	  //       delay(1000);
	        
	        cntr--;
		    break;
	}
		
	return 0;
}


void initDCMotor()
{
	pinMode(IN1_PIN, OUTPUT);
	pinMode(IN2_PIN, OUTPUT);
	pinMode(IN3_PIN, OUTPUT);
	pinMode(IN4_PIN, OUTPUT);
	pinMode(ENA_PIN, PWM_OUTPUT);
	pinMode(ENB_PIN, PWM_OUTPUT);
	digitalWrite(IN1_PIN, HIGH);
	digitalWrite(IN2_PIN, HIGH);
	digitalWrite(IN3_PIN, HIGH);
	digitalWrite(IN4_PIN, HIGH);						
	digitalWrite(ENA_PIN, HIGH);						
	digitalWrite(ENB_PIN, HIGH);						
}


void goForward()
{
		digitalWrite(IN1_PIN, HIGH);
		digitalWrite(IN2_PIN, LOW);
		digitalWrite(IN3_PIN, HIGH);
		digitalWrite(IN4_PIN, LOW);		
		//~ analogWrite(ENA_PIN, 50);
		//~ analogWrite(ENB_PIN, 50);
		printf("Forward\n");
}	


//~ void goBackward()
//~ {
		//~ digitalWrite(IN1_PIN, LOW);
		//~ digitalWrite(IN4_PIN, HIGH);
		//~ digitalWrite(IN5_PIN, LOW);
		//~ digitalWrite(IN6_PIN, HIGH);		
		//~ printf("Backwrad\n");
//~ }	
	
	
//~ void goLeft()
//~ {
		//~ digitalWrite(IN1_PIN, LOW);
		//~ digitalWrite(IN4_PIN, HIGH);
		//~ digitalWrite(IN5_PIN, HIGH);
		//~ digitalWrite(IN6_PIN, LOW);		
		//~ printf("Left\n");
//~ }	

//~ void goRight()
//~ {
		//~ digitalWrite(IN1_PIN, HIGH);
		//~ digitalWrite(IN4_PIN, LOW);
		//~ digitalWrite(IN5_PIN, LOW);
		//~ digitalWrite(IN6_PIN, HIGH);		
		//~ printf("Right\n");
//~ }	

void stopDCMotor()
{
		digitalWrite(IN1_PIN, LOW);
		digitalWrite(IN2_PIN, LOW);
		digitalWrite(IN3_PIN, LOW);
		digitalWrite(IN4_PIN, LOW);		
		printf("Stop\n");
}	
	

//gcc 1-motor_A.c -o motora -lwiringPi
// ./motora
