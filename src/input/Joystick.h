#pragma once

#include <Arduino.h>

#define pinX A1
#define pinY A2
#define ledPin 13
const int switchPin = 8;

class Joystick
{
private:
    bool state;
    bool lastState;

    bool stateUp;
    bool lastStateUp;

    bool stateDown;
    bool lastStateDown;

    bool stateRight;
    bool lastStateRight;

    bool stateLeft;
    bool lastStateLeft;

public:
    int x;
    int y;

    Joystick();

    void update();
    bool isPressed();
    bool isDown();
    bool isUp();
    bool isMovedDown();
    bool isMovedUp();
    bool isMovedLeft();
    bool isMovedRight();
};
