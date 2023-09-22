
#pragma once

#include <Arduino.h>
#include "Device.hpp"
#include "Time.h"
#include "extentions/Vector2Byte.h"


class Game
{
private:
protected:
public:
    String name = "NoName";
    String version = "0";
    String discription = "";

    Game(String& name, String& version)
    {
        this->name = name;
        this->version = version;
    }
    Game()
    {
    }

    virtual void awake() = 0;
    virtual void start() = 0;
    virtual void update() = 0;

    virtual void quit()
    {
        gameIsStarted = false;
        menuIsOpened = true;
    }
};
