#pragma once

#include <Arduino.h>
#include "extentions/Vector2Byte.h"
#include "extentions/Transform.h"
#include "extentions/GameObject.h"

class Rocket : public Transform
{
private:
    const uint8_t _speed {1};
    const uint8_t _damage{10};
    bool _isActive;

public:

    Rocket();

    void update();
    void destroy();
    void create(uint8_t x, uint8_t y);

    bool isActive() const {return _isActive;} 
    void setActive(bool state) { _isActive = state;}
};
