#pragma once

#include <Arduino.h>

class Vector2Byte
{
private:
public:
    uint8_t x = 0;
    uint8_t y = 0;

    Vector2Byte();
    Vector2Byte(uint8_t x, uint8_t y);

    void zero();
    void one();
    void up();
    void down();
    void left();
    void right();
    void normalize();

    static int distance(Vector2Byte v1, Vector2Byte v2);
    static Vector2Byte normalized(Vector2Byte v1, Vector2Byte v2);
};

Vector2Byte operator+(const Vector2Byte v1,const Vector2Byte v2);
Vector2Byte operator-(Vector2Byte v1, Vector2Byte v2);
Vector2Byte operator*(Vector2Byte v1, uint8_t scalar);
Vector2Byte operator/(Vector2Byte v1, uint8_t scalar);
bool operator>(Vector2Byte v1, Vector2Byte v2);
bool operator<(Vector2Byte v1, Vector2Byte v2);
bool operator<=(Vector2Byte v1, Vector2Byte v2);
bool operator>=(Vector2Byte v1, Vector2Byte v2);
