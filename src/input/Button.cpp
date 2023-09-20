#include "Button.h"

Button::Button(byte pin)
{
    this->pin = pin;
    pinMode(pin, INPUT_PULLUP);
}

void Button::update()
{
    lastState = state;
    state = digitalRead(pin);
}

bool Button::isPressed()
{
    return state;
}

bool Button::isDown()
{
    if (lastState == false && state != lastState)
        return true;

    return false;
}

bool Button::isUp()
{
    if (lastState == true && state != lastState)
        return true;

    return false;
}

bool Button::getState()
{
    return state;
}

bool Button::getLastState()
{
    return lastState;
}
