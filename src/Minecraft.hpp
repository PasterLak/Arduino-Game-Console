#pragma once

#include <Arduino.h>
#include "Game.hpp"

class Minecraft : public Game
{
private:

    byte x = Device::display.width() / 2;
    byte y = Device::display.height() / 2;
public:
    Minecraft(String name, String version) : Game(name, version)
    {

    }

    void awake() override
    {
        Device::display.clearDisplay();
    }
   
    void start() override
    {
        
    }
    void update() override
    {
        Device::joystick.update();
        Device::button.update();
        Device::display.clearDisplay();

        if(Device::joystick.x > 700) x--;
        if(Device::joystick.x < 300) x++;
        if(Device::joystick.y > 700) y--;
        if(Device::joystick.y < 300) y++;

        if(Device::button.isDown()) quit();

        if(x<= 0) x = 128;
        else if (x > 128) x = 0;

        if(y<= 0) y = 64;
        else if (y > 64) y = 0;

        Device::display.drawCircle(x,y,3, WHITE);

        Device::display.display();
    }
};