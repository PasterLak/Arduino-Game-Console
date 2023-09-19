#include "Joystick.h"

Joystick::Joystick()
{
    pinMode(ledPin, OUTPUT);
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);
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

void Joystick::update()
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

bool Joystick::isPressed()
{
    return state;
}

bool Joystick::isDown()
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

bool Joystick::isUp()
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

bool Joystick::isMovedDown()
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

bool Joystick::isMovedUp()
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

bool Joystick::isMovedLeft()
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

bool Joystick::isMovedRight()
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
