#pragma once
#include <Arduino.h>

#define pinX A1
#define pinY A2
#define ledPin 13
const int switchPin = 8;

class Joystick
{

private:
    bool state = 0;
    bool lastState = 0;

    bool stateUp = 0;
    bool lastStateUp = 0;

    bool stateDown = 0;
    bool lastStateDown = 0;

    bool stateRight = 0;
    bool lastStateRight = 0;

    bool stateLeft = 0;
    bool lastStateLeft = 0;

public:
    int x = 0;
    int y = 0;

    Joystick()
    {
        pinMode(ledPin, OUTPUT);
        pinMode(pinX, INPUT);
        pinMode(pinY, INPUT);

        // #define DDRC  B00000000
        //  PORTC B00000010
        //  PORTC B00000100
        // asm(
        //     "DDRС, B00000010" "\n"
        //     "sbi DDRС, 2" "\n"
        // );
        
        pinMode(switchPin, INPUT);
        digitalWrite(switchPin, HIGH);
        //#define DDRB 8
        // #define PORTB B00000001
        // asm (
        //     "SBI 0x05, 5"	"\n"

        // );
    }

    void update()
    {
        lastState = state;
        state = digitalRead(switchPin);

        digitalWrite(ledPin, state);

        x = analogRead(pinX);
        y = analogRead(pinY);

        lastStateDown = stateDown;
        lastStateUp = stateUp;
        lastStateRight = stateRight;
        lastStateLeft = stateLeft;


        if (y < 300)
            stateDown = 1;
        else
            stateDown = 0;

        if (y > 700)
            stateUp = 1;
        else
            stateUp = 0;
        
        if (x > 700)
            stateLeft = 1;
        else
            stateLeft = 0;
        if (x < 300)
            stateRight = 1;
        else
            stateRight = 0;
       

    }

    bool isPressed()
    {
        return state;
    }

    bool isDown()
    {
        if (lastState == false)
        {
            if (state != lastState)
            {
                return true;
            }
        }

        return false;
    }

    bool isUp()
    {
        if (lastState == true)
        {
            if (state != lastState)
            {
                return true;
            }
        }

        return false;
    }

    bool isMovedDown()
    {
        if (lastStateDown == false)
        {
            if (stateDown != lastStateDown)
            {
                return true;
            }
        }

        return false;
    }

    bool isMovedUp()
    {
        if (lastStateUp == false)
        {
            if (stateUp != lastStateUp)
            {
                return true;
            }
        }

        return false;
    }

    bool isMovedLeft()
    {
        if (lastStateLeft == false)
        {
            if (stateLeft != lastStateLeft)
            {
                return true;
            }
        }

        return false;
    }

    bool isMovedRight()
    {
        if (lastStateRight == false)
        {
            if (stateRight != lastStateRight)
            {
                return true;
            }
        }

        return false;
    }
};