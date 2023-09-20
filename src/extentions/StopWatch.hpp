#pragma once
#include <Arduino.h>

class StopWatch
{
    public:

    void start()
    {
        endTime = 0;
        startTime = Arduino_h::millis();
    }
    void end()
    {
        endTime = Arduino_h::millis();
    }
    unsigned long elapsedTime()
    {
        return (endTime - startTime) / 1000;
    }

    private:

    unsigned long startTime;
    unsigned long endTime;

};