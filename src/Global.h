#ifndef Global_h
#define Global_h

#include <Arduino.h>

static unsigned int deltaTime(0);

static unsigned long oldTime(0);

static void updateDelta()
{

    deltaTime = Arduino_h::millis() - oldTime;
    oldTime = Arduino_h::millis();

}

static unsigned int fps()
{
    if(deltaTime > 0)
    return 1000 / deltaTime ;
    else return 0;
}


#endif
