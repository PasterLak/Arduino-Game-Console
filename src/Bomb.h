#pragma once

#include <Arduino.h>
#include "extentions/Vector2Byte.h"

#define SPAWN_POS 15

class Bomb
{
private:
    const byte speed = 1;
    const byte damage = 10;

public:
    Vector2Byte position;

    bool isActive;

    Bomb();

    void update();

    void destroy();

    void create(int x);
};