#pragma once

#include <Arduino.h>
#include "extentions/Vector2Byte.h"

class Submarine 
{
private:
    uint8_t speed = 1;
    const uint8_t damage = 10;
    bool _isActive = false;

public:
    Vector2Byte position;
    int8_t direction;

    Submarine();
    Submarine(int8_t direction);
    ~Submarine() = default;

    bool isActive() const;
    void update();
    void destroy();
    void create();
};
