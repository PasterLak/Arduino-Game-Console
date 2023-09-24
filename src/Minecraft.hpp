#pragma once

#include <Arduino.h>
#include "Game.h"
#include "extentions/Trigger2D.h"

class Minecraft : public Game
{
private:
    Trigger2D trigger{0, 0, 25, 25};
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

        if (Device::button.isDown())
            quit();


        if (Device::joystick.x > 700)
            x--;
        if (Device::joystick.x < 300)
            x++;
        if (Device::joystick.y > 700)
            y--;
        if (Device::joystick.y < 300)
            y++;

        if (x <= 0)
            x = 128;
        else if (x > 128)
            x = 0;

        if (y <= 0)
            y = 64;
        else if (y > 64)
            y = 0;


        trigger.update(x, y);

        
    }

    void draw() override final
    {
        Device::display.clearDisplay();
        if (name == "Minecraft")
        {
            Device::display.clearDisplay();
            Device::display.drawBitmap(0, 0, minecraft, 128, 64, WHITE);
            Device::display.display();

            return;
        }

        Device::display.drawCircle(x, y, 3, WHITE);
        Device::display.drawRect(0, 0, 25, 25, WHITE);

        if (trigger.isActive && trigger.isInside(x, y))
        {

            Device::display.drawCircle(30, 30, 3, WHITE);
        }

        Device::display.display();
    }

    void quit() override
    {
        x = Device::display.width() / 2;
        y = Device::display.height() / 2;

        Game::quit();
    }
};