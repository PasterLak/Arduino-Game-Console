#pragma once
#include "extentions/Transform.h"
#include "extentions/Vector2Byte.h"

class Trigger2D
{
private:
    int minX;
    int minY;
    int maxX;
    int maxY;
    bool inside;

protected:
    virtual void OnTriggerEnter();
    virtual void OnTriggerExit();
    virtual void OnTriggerStay();

public:
    bool isActive = true;
    Trigger2D(int x1, int y1, int x2, int y2);

    void update(Transform transform);
    void update(Vector2Byte vector2Byte);
    void update(int x, int y);

    bool isInside(Transform transform);
    bool isInside(Vector2Byte vector2Byte);
    bool isInside(int x, int y);
    

    void setSize(int x1, int y1, int x2, int y2);

};
