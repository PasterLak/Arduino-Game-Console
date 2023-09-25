#ifndef Time_h
#define Time_h

#include <Arduino.h>

static unsigned int deltaTime(0);

static unsigned long oldTime(0);

#pragma GCC diagnostic ignored "-Wunused-function"
static void updateDelta()
{

    deltaTime = Arduino_h::millis() - oldTime;
    oldTime = Arduino_h::millis();

}

#pragma GCC diagnostic ignored "-Wunused-function"
static unsigned int fps()
{
    if(deltaTime > 0)
    return 1000 / deltaTime ;
    else return 0;
}

#pragma GCC diagnostic ignored "-Wunused-function"
static float getSeconds()
{
   return deltaTime / 1000.0f;
}


#endif
