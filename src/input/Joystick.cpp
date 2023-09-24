#include "Joystick.h"

#define maxAxisValue 700
#define minAxisValue 300

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

    stateDown = (y < minAxisValue) ? 1 : 0;
    stateUp = (y > maxAxisValue) ? 1 : 0;
    stateLeft = (x > maxAxisValue) ? 1 : 0;
    stateRight = (x < minAxisValue) ? 1 : 0;
}

bool Joystick::isPressed()
{
    return state;
}

bool Joystick::isDown() {
    return (lastState == false && state != lastState);
}


bool Joystick::isUp()
{
    return (lastState == true && state != lastState);
}

bool Joystick::isMovedDown() {
    return (lastStateDown == false && stateDown != lastStateDown);
}


bool Joystick::isMovedUp() {
    return (lastStateUp == false && stateUp != lastStateUp);
}


bool Joystick::isMovedLeft()
{
    return (lastStateLeft == false && stateLeft != lastStateLeft);
}

bool Joystick::isMovedRight()
{
    return (lastStateRight == false && stateRight != lastStateRight);
}
