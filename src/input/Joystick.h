#pragma once

#include <Arduino.h>

#define ledPin 13
const int switchPin = 8;

class Joystick
{
private:
    const uint8_t _pinX;
    const uint8_t _pinY;

    bool xAxisMirror = false;
    bool yAxisMirror = false;

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

    Joystick() :  _pinX(0), _pinY(1){
        Joystick(_pinX,_pinY);
    }

    Joystick(uint8_t pinX, uint8_t pinY, bool xAxisMirror, bool yAxisMirror) :  _pinX(pinX), _pinY(pinY){
        setAxisMirror(xAxisMirror,yAxisMirror);
        Joystick(_pinX,_pinY);
    }

    Joystick(uint8_t pinX, uint8_t pinY) : _pinX(pinX), _pinY(pinY)
    {
        pinMode(ledPin, OUTPUT);
        pinMode(_pinX, INPUT);
        pinMode(_pinY, INPUT);
        pinMode(switchPin, INPUT);
        digitalWrite(switchPin, HIGH);

        state = 0;
        lastState = 0;

        stateUp = 0;
        lastStateUp = 0;

        stateDown = 0;
        lastStateDown = 0;

        stateRight = 0;
        lastStateRight = 0;

        stateLeft = 0;
        lastStateLeft = 0;
    }

    void setAxisMirror(bool x, bool y)
    {
        xAxisMirror = x;
        yAxisMirror = y;
    }

    void update();
    bool isPressed();
    bool isButtonDown();
    bool isButtonUp();

    bool isMovedDown();
    bool isMovedUp();
    bool isMovedLeft();
    bool isMovedRight();

    bool isDown();
    bool isUp();
    bool isLeft();
    bool isRight();
};
