#pragma once

#include <Arduino.h>
#include "Game.h"
#include "Engine.hpp"


class Debug : public Game
{
private:
 

public:
    Debug(String name, String version) : Game(name, version)
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
        {
            gameIsStarted = false;
            menuIsOpened = true;
        }
    }

    void draw() override final
    {
        Device::display.clearDisplay();

        Device::display.drawRect(0, 0, 128, 64, WHITE);

        Device::display.setCursor(5, 5);

        Device::display.println("Memory: 32Kb"  );

        Device::display.setCursor(5, 15);
        Device::display.println("X: " + String(Device::joystick.x) + " Y: " + String(Device::joystick.y));

        Device::display.setCursor(5, 25);
        Device::display.println("FrameTime: " + String(deltaTime) + " ms.");

        Device::display.setCursor(5, 35);
        Device::display.println("Fps: " + String(1000 / deltaTime));
        Device::display.setCursor(5, 45);
        Device::display.println("Screen: " + String(Device::display.width()) + "/" + String(Device::display.height()));

        Device::display.setCursor(5, 54);
        Device::display.println("<- Back");

        Device::display.display();
    }
};