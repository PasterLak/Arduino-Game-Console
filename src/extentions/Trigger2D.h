#pragma once
#include "extentions/Transform.h"
#include "extentions/Vector2Byte.h"

class Trigger2D
{
private:
    uint16_t minX;
    uint16_t minY;
    uint16_t maxX;
    uint16_t maxY;
    bool inside;

protected:
    virtual void OnTriggerEnter();
    virtual void OnTriggerExit();
    virtual void OnTriggerStay();

public:
    bool isActive = true;
    Trigger2D(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

    void update(Transform &transform);
    void update(Vector2Byte &vector2Byte);
    void update(uint16_t x, uint16_t y);

    bool isInside(Transform &transform);
    bool isInside(Vector2Byte &vector2Byte);
    bool isInside(uint16_t x, uint16_t y);
    

    void setSize(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

};
