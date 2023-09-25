#include "Bomb.h"

Bomb::Bomb()
{
    isActive = false;
    position = {0, SPAWN_POS};
}

void Bomb::update()
{
    if (!isActive)
        return;

    position.y += speed;

    if (position.y > 64)
        destroy();
}

void Bomb::destroy()
{
    isActive = false;
}

void Bomb::create(uint8_t x)
{
    isActive = true;
    position.x = x;
    position.y = SPAWN_POS;
}
