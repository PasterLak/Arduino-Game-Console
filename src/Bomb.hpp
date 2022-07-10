#pragma once
#include <Arduino.h>
#include "Vector2Byte.hpp"

#define SPAWN_POS 15

class Bomb
{
private:
    const byte speed = 1;
    const byte damage = 10;

public:
    Vector2Byte position = {0, SPAWN_POS};

    bool isActive = false;

    Bomb()
    {
    }

    void update()
    {
        if (isActive)
        {
            position.y += speed;

            if (position.y > 64)
                destroy();
        }
    }

    void destroy()
    {
        isActive = false;
    }

    void create(int x)
    {
        isActive = true;
        position.x = x;
        position.y = SPAWN_POS;
    }
};