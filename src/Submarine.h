#pragma once

#include <Arduino.h>
#include "Vector2Byte.h"

class Submarine 
{
private:
    byte speed = 1;
    const byte damage = 10;
    bool _isActive = false;

public:
    Vector2Byte position;
    int8_t direction;

    Submarine();
    Submarine(int8_t direction);

    bool isActive();
    void update();
    void destroy();
    void create();
};