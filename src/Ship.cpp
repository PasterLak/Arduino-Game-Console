#include "Ship.h"

Ship::Ship()
{
    hp = maxHp;
    position = {64, shipY};
    timeToReload = 0;
    _canShot = true;
}

void Ship::update()
{
    if (timeToReload > 0)
        timeToReload -= deltaTime;

    if (timeToReload <= 0)
    {
        _canShot = true;
    }
}

void Ship::destroy()
{
    hp = 0;
}

void Ship::create()
{
    hp = maxHp;
    position.x = 64;
    position.y = shipY;
}

void Ship::shot()
{
    _canShot = false;
    timeToReload = reloadTime;
}

void Ship::setDamage()
{
    hp--;
}

byte Ship::getSpeed()
{
    return speed;
}

byte Ship::getHp()
{
    return hp;
}

void Ship::setHp(u_int8_t val)
{
    hp = val;
}

bool Ship::canShot()
{
    return _canShot;
}
