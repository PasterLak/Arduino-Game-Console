#include "Rocket.h"

Rocket::Rocket()
{
    isActive = false;
    position = Vector2Byte(0, 0);
}

void Rocket::update() 
{
    if (isActive)
    {
        position.y -= _speed;

        if (position.y <= 0)
            destroy();
    }
}

void Rocket::destroy()
{
    isActive = false;
}

void Rocket::create(int x, int y)
{
    isActive = true;
    position.x = x;
    position.y = y;
}
