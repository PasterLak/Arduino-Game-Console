#include "Joystick.h"

#define maxAxisValue 700
#define minAxisValue 300


void Joystick::update()
{
    lastState = state;
    state = digitalRead(switchPin);
    digitalWrite(ledPin, state);

    

    x = analogRead(_pinX);
    y = analogRead(_pinY);

    //Serial.println(String(x) + " : " + String(y));

    lastStateDown = stateDown;
    lastStateUp = stateUp;
    lastStateRight = stateRight;
    lastStateLeft = stateLeft;

  if(yAxisMirror)
  {
    stateUp = (y  < minAxisValue) ? 1 : 0;
    stateDown = (y > maxAxisValue) ? 1 : 0;

  }
  else 
  {
    stateDown = (y  < minAxisValue) ? 1 : 0;
    stateUp = (y > maxAxisValue) ? 1 : 0;
  }

  if(xAxisMirror)
  {
    stateRight = (x > maxAxisValue) ? 1 : 0;
    stateLeft = (x < minAxisValue) ? 1 : 0;
  }
  else
  {
    stateLeft = (x > maxAxisValue) ? 1 : 0;
    stateRight = (x < minAxisValue) ? 1 : 0;
  }
  

    
}

bool Joystick::isPressed()
{
    return state;
}

bool Joystick::isButtonDown() {
    return (lastState == false && state != lastState);
}


bool Joystick::isButtonUp()
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


bool Joystick::isDown() {
    return (lastStateDown == true && stateDown == lastStateDown);
}


bool Joystick::isUp() {
    return (lastStateUp == true && stateUp == lastStateUp);
}


bool Joystick::isLeft()
{
    return (lastStateLeft == true && stateLeft == lastStateLeft);
}

bool Joystick::isRight()
{
    return (lastStateRight == true && stateRight == lastStateRight);
}