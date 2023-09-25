#pragma once

#include <Arduino.h>
#include "extentions/Vector2Byte.h"
#include "Time.h"
#include "extentions/Transform.h"

class Ship : public Transform
{
private:
    const uint8_t speed = 4;
    const uint8_t maxHp = 3;
    const short reloadTime = 500;

    const uint8_t shipY = 5;

    uint8_t hp;
    short timeToReload;
    bool _canShot;

public:
    Ship();

    void update();
    void destroy();
    void create();
    void shot();
    void setDamage();
    uint8_t getSpeed() const;
    uint8_t getHp() const;
    void setHp(u_int8_t hp);
    bool canShot() const;
    void setCanShot(bool state){
        _canShot = state;
    timeToReload = state ? (short)0 : reloadTime;
    }
};
