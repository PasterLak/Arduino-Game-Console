#pragma once

#include <Arduino.h>
#include "extentions/Vector2Byte.h"
#include "extentions/Transform.h"

class Rocket : public Transform
{
private:
    const byte speed = 1;
    const byte damage = 10;

public:
    bool isActive;

    Rocket();

    void update();
    void destroy();
    void create(int x, int y);
};
