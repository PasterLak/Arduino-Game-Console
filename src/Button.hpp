#pragma once
#include <Arduino.h>

class Button
{

private:
    byte pin;
    bool state = 0;
    bool lastState = 0;

public:
    Button(byte pin)
    {
        this->pin = pin;
        pinMode(pin, INPUT_PULLUP);
        //attachInterrupt(0, update, FALLING);
    }

    void update()
    {
        lastState = state;
        state = digitalRead(pin);
    }

    bool isPressed()
    {
        return state;
    }

    bool isDown()
    {
        if (lastState == false)
            if (state != lastState)
                return true;

        return false;
    }

    bool isUp()
    {
        if (lastState == true)
            if (state != lastState)
                return true;

        return false;
    }

    bool getState()
    {
        return state;
    }

    bool getLastState()
    {
        return lastState;
    }
};