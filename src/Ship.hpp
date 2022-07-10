#pragma once
#include <Arduino.h>
#include "Vector2Byte.hpp"
#include "Global.h"

class Ship
{
private:
    const byte speed = 4;
    const byte maxHp = 3;
    const int reloadTime = 500;

    const byte shipY = 5;

public:

    byte hp = maxHp;
    Vector2Byte position = {64, shipY};
    int timeToReload = 0;

    bool canShot = true;

    Ship()
    {
    }


    void update()
    {
        if(timeToReload > 0) timeToReload -= deltaTime;

        if(timeToReload <= 0)
        {
            canShot = true;
            
        }

        
    }

    void destroy()
    {
        hp = 0;

    }
    void create()
    {
        hp = maxHp;
        position.x = 64;
        position.y = shipY;
    }

    void shot()
    {
        canShot = false;
        timeToReload = reloadTime;
    }

    void setDamage()
    {

        hp--;

    }

    byte getSpeed()
    {
        return speed;
    }
    byte getHp()
    {
        return hp;
    }
};