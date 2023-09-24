#include "Rocket.h"

Rocket::Rocket()
{
    setActive(false);
    position = Vector2Byte(0, 0);
}

 void Rocket::update()
{
    if (isActive())
    {
        position.y -= _speed;

        if (position.y <= 0)
            destroy();
    }
}

void Rocket::destroy()
{
    setActive(false);
}

void Rocket::create(uint8_t x, uint8_t y)
{
    setActive(true);
    position.x = x;
    position.y = y;
}
