#define LEFT_TRACER_PIN 10
#define RIGHT_TRACER_PIN 11

void InitLineTacer();
void LineTracerThread();
void LineTracerTest();

void InitLineTacer() {
    pinMode(LEFT_TRACER_PIN, INPUT);
    pinMode(RIGHT_TRACER_PIN, INPUT);
}

PI_THREAD(lineTracerThread) {
	InitLineTacer();
    while(1) {
        leftTracer = digitalRead(LEFT_TRACER_PIN);
        rightTracer = digitalRead(RIGHT_TRACER_PIN);
    }
    
}

void LineTracerThread() {
    if(piThreadCreate(lineTracerThread) != 0) {
        printf("Line Tracer not initialized\n");
    }
}

void LineTracerTest(){
      while (1) {
       
         if (leftTracer == 0 && rightTracer == 1) {
            printf("Left line tracer\n");
            
         
        } else if (rightTracer == 0 && leftTracer == 1) {
            printf("Right line tracer\n");

         
        } else if (rightTracer == 0 && leftTracer == 0) {
            printf("Both line tracers\n");
           
            
        
        } else if (rightTracer == 1 && leftTracer == 1) {
             printf("None line tracers\n");
        }
    }
   
}
