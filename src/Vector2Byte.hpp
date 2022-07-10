#pragma once

#include <Arduino.h>

class Vector2Byte
{

private:
public:
    uint8_t x = 0;
    uint8_t y = 0;
    
    Vector2Byte()
    {
    }
    Vector2Byte(uint8_t x, uint8_t y)
    {
        this->x = x;
        this->y = y;
    }

    void zero()
    {
        x = 0;
        y = 0;
    }

    void one()
    {
        x = 1;
        y = 1;
    }

    void up()
    {
        x = 0;
        y = 1;
    }

    void down()
    {
        x = 0;
        y = -1;
    }

    void left()
    {
        x = -1;
        y = 0;
    }

    void right()
    {
        x = 1;
        y = 0;
    }

    void normalize()
    {

        int dis = distance(Vector2Byte(0,0), Vector2Byte(x,y));

        x = uint8_t(x/ dis); 
        y = uint8_t(y/ dis);
    }

    static int distance(Vector2Byte v1, Vector2Byte v2)
    {

        int dis = sqrt((v1.x - v2.x) * (v1.x - v2.x) +
                        (v1.y - v2.y) * (v1.y - v2.y));

        return dis;
    }

    static Vector2Byte normalized(Vector2Byte v1, Vector2Byte v2)
    {

        int dis = distance(v1,v2);

        return Vector2Byte( uint8_t(v1.x/ dis), uint8_t(v2.y/ dis));
    }

};

Vector2Byte operator+(Vector2Byte v1, Vector2Byte v2)
{
    return Vector2Byte(v1.x + v2.x, v1.y + v2.y);
}

Vector2Byte operator-(Vector2Byte v1, Vector2Byte v2)
{
    return Vector2Byte(v1.x - v2.x, v1.y - v2.y);
}

Vector2Byte operator*(Vector2Byte v1, uint8_t scalar )
{
    return Vector2Byte(v1.x * scalar, v1.y * scalar);
}

Vector2Byte operator/(Vector2Byte v1, uint8_t scalar )
{
    return Vector2Byte(v1.x / scalar, v1.y / scalar);
}

bool operator>(Vector2Byte v1, Vector2Byte v2)
{
    return v1.x > v2.x && v1.y> v2.y;
}
bool operator<(Vector2Byte v1, Vector2Byte v2)
{
    return v1.x < v2.x && v1.y < v2.y;
}
bool operator<=(Vector2Byte v1, Vector2Byte v2)
{
    return v1.x <= v2.x && v1.y <= v2.y;
}
bool operator>=(Vector2Byte v1, Vector2Byte v2)
{
    return v1.x >= v2.x && v1.y >= v2.y;
}

