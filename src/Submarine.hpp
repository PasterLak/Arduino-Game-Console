#pragma once
#include <Arduino.h>
#include "Vector2Byte.hpp"

class Submarine
{
private:
    byte speed = 1;
    const byte damage = 10;
    bool _isActive = false;

public:
    Vector2Byte position = {0, 20};

    
    int8_t direction = -1;

    Submarine()
    {
    }

    Submarine(int8_t direction)
    {
        if (direction == 1 || direction == -1)
            this->direction = direction;
    }

    bool isActive()
    {
        return _isActive;
    }

    void update()
    {
        if (_isActive)
        {
            position.x += speed * direction;

            if (direction == -1)
            {
                if (position.x < 0)
                    destroy();
            }
            else if (direction == 1)
            {
                if (position.x > 128)
                    destroy();
            }
        }
    }

    void destroy()
    {
        _isActive = false;
    }
    void create()
    {
        _isActive = true;

        if (direction == -1)
            position.x = 128;
        else
            position.x = 0;

        position.y = random(35, 55);
        speed = random(1, 2);
    }
};