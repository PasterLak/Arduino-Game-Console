#pragma once
#include <Arduino.h>
#include "Vector2Byte.hpp"

class Rocket
{
private:
    const byte speed = 1;
    const byte damage = 10;

public:

    Vector2Byte position = {0,0};

    bool isActive = false;

    Rocket()
    {
    }

    void update()
    {
        if (isActive)
        {
            position.y -= speed;

            if (position.y <= 0)
                destroy();
        }
    }

    void destroy()
    {
        isActive = false;
    }

    void create(int x, int y)
    {
        isActive = true;
        position.x = x;
        position.y = y;
    }
};