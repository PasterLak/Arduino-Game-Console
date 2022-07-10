#pragma once

#include "Engine.hpp"

class ConsoleMenu
{
private:
public:
    //bool isOpened = false;

    ConsoleMenu()
    {
    }

    void start()
    {
    }
    void draw()
    {
        if (!menuIsOpened)
            return;

        Device::joystick.update();

        if (Device::joystick.isMovedDown())
        {
            if (selectedGameID + 1 < GamesCount)
                selectedGameID++;
            else
                selectedGameID = 0;
        }
        else if (Device::joystick.isMovedUp())
        {
            if (selectedGameID - 1 >= 0)
                selectedGameID--;
            else
                selectedGameID = GamesCount - 1;
        }

        if (Device::joystick.isMovedRight())
        {
            menuIsOpened = false;
            gameIsStarted = true;
            Device::display.clearDisplay();
            delay(500);
            return;
        }

        Device::display.clearDisplay();

        Device::display.drawRect(0, 0, 128, 64, WHITE);

        for (byte i = 0; i < GamesCount; i++)
        {
            Device::display.setCursor(4, 5 + i * 10);
            if (selectedGameID == i)
                Device::display.println(">");

            Device::display.setCursor(12, 5 + i * 10);
            Device::display.println(games[i]->name);
        }

        Device::display.display();
    }

    void startGame()
    {
    }
};