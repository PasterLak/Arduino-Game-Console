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
    position.x = (uint8_t)64;
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

uint8_t Ship::getSpeed() const
{
    return speed;
}

uint8_t Ship::getHp() const
{
    return hp;
}

void Ship::setHp(u_int8_t val)
{
    hp = val;
}

bool Ship::canShot() const
{
    return _canShot;
}
