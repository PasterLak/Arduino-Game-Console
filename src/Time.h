#ifndef Time_h
#define Time_h

#include <Arduino.h>

extern uint8_t deltaTime;

extern unsigned long oldTime;


static void updateDelta()
{


    deltaTime = static_cast<uint8_t>(Arduino_h::millis() - oldTime);
    oldTime = Arduino_h::millis();

}


static unsigned int fps()
{
    if(deltaTime > 0)
    return 1000 / deltaTime ;
    else return 0;
}

static float getSeconds()
{
   return deltaTime / 1000.0f;
}


#endif
