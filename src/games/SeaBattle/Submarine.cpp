#include "Submarine.h"

Submarine::Submarine()
{
}

Submarine::Submarine(int8_t direction)
{
    if (direction == 1 || direction == -1)
        this->direction = direction;
}

bool Submarine::isActive() const
{
    return _isActive;
}

void Submarine::update()
{
    if (!_isActive)
        return;

    position.x += speed * direction;

    if (direction == -1)
    {
        if (position.x < 0)
            destroy();
    }
    else if (direction == 1)
    {
        if (position.x > 128)
            destroy();
    }
}

void Submarine::destroy()
{
    _isActive = false;
}

void Submarine::create()
{
    _isActive = true;

    position.x = (direction == -1) ? 128 : 0;

    position.y = random(35, 55);
    speed = random(1, 2);
}
