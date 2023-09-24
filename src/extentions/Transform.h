#pragma once
#include "Vector2Byte.h"

class Transform
{

protected:
    Vector2Byte position{0,0};

public:
    uint8_t getPositionX()
    {
        return position.x;
    }

    uint8_t getPositionY()
    {
        return position.y;
    }

    void setPosition(uint8_t x, uint8_t y)
    {
        position.x = x;
        position.y = y;
    }

    void setPositionX(uint8_t x)
    {
        position.x = x;
    }

    void setPositionY(uint8_t y)
    {
        position.y = y;
    }

    Vector2Byte getPosition()
       {
        return position;
    }
};
