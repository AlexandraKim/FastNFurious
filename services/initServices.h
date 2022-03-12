#include "../states.h"
#include "sensors/ultrasonic.h"
#include "sensors/irsensor.h"
#include "sensors/lineTracer.h"
#include "dcmotor.h"

void InitServices();

void InitServices(){
    LineTracerThread();
    IrThread();
    UltrasonicThread();
    initSoftDCMotor();
}

