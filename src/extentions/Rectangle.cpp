#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {
}

bool Rectangle::collidesWith(const Rectangle& other) const {
    
    return (x + width >= other.x) && (x <= other.x + other.width) &&
           (y + height >= other.y) && (y <= other.y + other.height);
}

bool Rectangle::containsPoint(int pointX, int pointY) const {
    
    return (pointX >= x) && (pointX <= x + width) &&
           (pointY >= y) && (pointY <= y + height);
}
