#pragma once
#include "Vector2Byte.hpp"

class Trigger2D
{
private:
    Vector2Byte min;
    Vector2Byte max;

    Vector2Byte object;
    bool lastState = false;
    bool state = false;

public:
    Trigger2D(Vector2Byte min, Vector2Byte max)
    {
        if (min > max)
        {
            this->min = max;
            this->max = min;
        }
        this->min = min;
        this->max = max;
    }

    bool intersects(Vector2Byte objectPosition)
    {
        if (objectPosition.x >= min.x && objectPosition.x <= max.x &&
            objectPosition.y >= min.y && objectPosition.y <= max.y)
            return true;

        return false;
    }

    void update(Vector2Byte objectPosition)
    {
        lastState = state;
        state = intersects(objectPosition);
    }

    virtual void onTriggerEnter()
    {
        if (state == true && lastState == false)
        {
        }
    }
    virtual void onTriggerStay()
    {
        if (state == true && lastState == true)
        {
        }
    }
    virtual void onTriggerExit()
    {
        if (state == false && lastState == true)
        {
        }
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