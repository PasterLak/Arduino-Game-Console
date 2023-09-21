#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
    int x;
    int y;
    int width;
    int height;

    Rectangle(int x, int y, int width, int height);
    bool collidesWith(const Rectangle& other) const;
    bool containsPoint(int pointX, int pointY) const;
};

#endif // RECTANGLE_H
