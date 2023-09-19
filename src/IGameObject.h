// Interface.h
#pragma once

class RocketInterface
{
public:
    virtual void update() = 0;
    virtual void destroy() = 0;
    virtual void create(int x, int y) = 0;
};
