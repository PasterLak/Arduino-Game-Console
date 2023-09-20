#pragma once
#include <Arduino.h>

class Button
{
private:
    byte pin;
    bool state = 0;
    bool lastState = 0;

public:
    Button(byte pin);
    void update();
    bool isPressed();
    bool isDown();
    bool isUp();
    bool getState();
    bool getLastState();
};
