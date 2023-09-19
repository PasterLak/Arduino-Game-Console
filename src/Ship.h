#pragma once

#include <Arduino.h>
#include "Vector2Byte.h"
#include "Time.h"
#include "Transform.h"

class Ship : public Transform
{
private:
    const byte speed = 4;
    const byte maxHp = 3;
    const int reloadTime = 500;

    const byte shipY = 5;

    byte hp;
    int timeToReload;
    bool _canShot;

public:
    Ship();

    void update();
    void destroy();
    void create();
    void shot();
    void setDamage();
    byte getSpeed();
    byte getHp();
    void setHp(u_int8_t hp);
    bool canShot();
};
