#pragma once

#include <Arduino.h>
#include "extentions/Vector2Byte.h"
#include "extentions/Transform.h"
#include "extentions/GameObject.h"

class Rocket : public Transform
{
private:
    const byte _speed {1};
    const byte _damage{10};

public:
    bool isActive;

    Rocket();

    void update();
    void destroy();
    void create(int x, int y);
};
