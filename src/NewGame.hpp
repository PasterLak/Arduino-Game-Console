// This is a template for creating a own game
#pragma once

#include <Arduino.h>
#include "Game.h"

class NewGame : public Game
{
private:
public:

    NewGame(String name, String version) : Game(name, version)
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
        Device::display.clearDisplay();

        Device::display.display();
    }

    void draw() override final
    {

    }
};