#pragma once
#include <Arduino.h>

class Animation
{
private:
public:
    int posX = 0;
    int posY = 0;

    int time;
    int liveTime;

    bool isPlay = false;

    Animation()
    {
    }
    Animation(int x, int y, int liveTime)
    {
        time = liveTime;
        posX = x;
        posY = y;
    }

    void update()
    {
    }

    void play()
    {
    }
    void stop()
    {
    }
};