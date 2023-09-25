#include "Vector2Byte.h"
#include <array>

Vector2Byte::Vector2Byte()
{
    zero();
}

Vector2Byte::Vector2Byte(const Vector2Byte& v)
{
    *this = v;
}

Vector2Byte::Vector2Byte(uint8_t x, uint8_t y)
{
    this->x = x;
    this->y = y;
}

void Vector2Byte::zero()
{
    x = 0;
    y = 0;
}

void Vector2Byte::one()
{
    x = 1;
    y = 1;
}

void Vector2Byte::up()
{
    x = 0;
    y = 1;
}

void Vector2Byte::down()
{
    x = 0;
    y = -1;
}

void Vector2Byte::left()
{
    x = -1;
    y = 0;
}

void Vector2Byte::right()
{
    x = 1;
    y = 0;
}

void Vector2Byte::normalize()
{
    int dis = distance(Vector2Byte(0, 0), *this);
    x = uint8_t(x / dis);
    y = uint8_t(y / dis);
}

int Vector2Byte::distance(Vector2Byte v1, Vector2Byte v2)
{
    int dis = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
    return dis;
}

Vector2Byte Vector2Byte::normalized( Vector2Byte& v1, Vector2Byte& v2)
{
    int dis = distance(v1, v2);
    return Vector2Byte(uint8_t(v1.x / dis), uint8_t(v2.y / dis));
}

Vector2Byte& Vector2Byte::operator=(const Vector2Byte& v1)
{
    x = v1.x; 
    y = v1.y;
    return *this;
}
/*
Vector2Byte& Vector2Byte::operator=( Vector2Byte&& v1)
{
    swap(v1.x, this->x);
    swap(v1.y, this->y);
    return *this;
}
*/

Vector2Byte operator+(const Vector2Byte v1, const Vector2Byte v2)
{
    return Vector2Byte(v1.x + v2.x, v1.y + v2.y);
}

Vector2Byte operator-(Vector2Byte v1, Vector2Byte v2)
{
    return Vector2Byte(v1.x - v2.x, v1.y - v2.y);
}

Vector2Byte operator*(Vector2Byte v1, uint8_t scalar)
{
    return Vector2Byte(v1.x * scalar, v1.y * scalar);
}

Vector2Byte operator/(Vector2Byte v1, uint8_t scalar)
{
    return Vector2Byte(v1.x / scalar, v1.y / scalar);
}

bool operator>(Vector2Byte v1, Vector2Byte v2)
{
    return v1.x > v2.x && v1.y > v2.y;
}

bool operator<(const Vector2Byte v1, const Vector2Byte v2)
{
    return v1.x < v2.x && v1.y < v2.y;
}

bool operator<=(const Vector2Byte v1, const Vector2Byte v2)
{
    return v1.x <= v2.x && v1.y <= v2.y;
}

bool operator>=(const Vector2Byte v1, const Vector2Byte v2)
{
    return v1.x >= v2.x && v1.y >= v2.y;
}
