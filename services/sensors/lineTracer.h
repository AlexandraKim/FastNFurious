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
        LeftTracer = digitalRead(LEFT_TRACER_PIN);
        RightTracer = digitalRead(RIGHT_TRACER_PIN);
    }
    
}

void LineTracerThread() {
    if(piThreadCreate(lineTracerThread) != 0) {
        printf("Line Tracer not initialized\n");
    }
}

void LineTracerTest() {
    while (1) {
        if (LeftTracer == 0 && RightTracer == 1) {
            printf("Left line tracer\n");
        } else if (RightTracer == 0 && LeftTracer == 1) {
            printf("Right line tracer\n");
        } else if (RightTracer == 0 && LeftTracer == 0) {
            printf("Both line tracers\n");
        } else if (RightTracer == 1 && LeftTracer == 1) {
             printf("None line tracers\n");
        }
    }
}
