#include "Trigger2D.h"
#include <Arduino.h>

Trigger2D::Trigger2D(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    setSize(x1,  y1,  x2,  y2);
    inside = false;
}

void Trigger2D::update(Vector2Byte &vector2Byte)
{
    update(vector2Byte.x, vector2Byte.y);
}

void Trigger2D::update(Transform &transform)
{
    update(transform.getPositionX(), transform.getPositionY());
}

void Trigger2D::update(uint16_t x, uint16_t y)
{
    bool currentlyInside = isInside(x, y);

    if (currentlyInside && !inside)
    {
        inside = true;
        OnTriggerEnter();
    }
    else if (!currentlyInside && inside)
    {
        inside = false;
        OnTriggerExit();
    }
    else if (currentlyInside)
    {
        OnTriggerStay();
    }
}

bool Trigger2D::isInside(uint16_t x, uint16_t y)
{
    return (x >= minX && x <= maxX && y >= minY && y <= maxY);
}

bool Trigger2D::isInside(Vector2Byte &vector2Byte)
{
    isInside(vector2Byte.x, vector2Byte.y);
}

bool Trigger2D::isInside(Transform &transform)
{
    isInside(transform.getPositionX(), transform.getPositionY());
}

void Trigger2D::OnTriggerEnter()
{
   
}

void Trigger2D::OnTriggerExit()
{
   
}

void Trigger2D::OnTriggerStay()
{
   
}


void Trigger2D::setSize(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    minX = min(x1, x2);
    minY = min(y1, y2);
    maxX = max(x1, x2);
    maxY = max(y1, y2);

}
