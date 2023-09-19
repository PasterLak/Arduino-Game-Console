#pragma once

#include "Engine.hpp"

class ConsoleMenu
{
private:

public:
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

        handleJoystickInput();

        if (shouldStartGame())
        {
            startSelectedGame();
            return;
        }

        clearDisplay();
        drawMenu();
        displayMenu();
    }

    void startGame()
    {
    }

private:
    void handleJoystickInput()
    {

        if (Device::joystick.isMovedDown())
        {
            selectedGameID = (selectedGameID + 1) % GamesCount;
        }
        else if (Device::joystick.isMovedUp())
        {
            selectedGameID = (selectedGameID - 1 + GamesCount) % GamesCount;
        }
    }

    bool shouldStartGame()
    {
        return Device::joystick.isMovedRight();
    }

    void startSelectedGame()
    {
        menuIsOpened = false;
        gameIsStarted = true;
        Device::display.clearDisplay();
        delay(500);
    }

    void clearDisplay()
    {
        Device::display.clearDisplay();
        Device::display.drawRect(0, 0, 128, 64, WHITE);
    }

    void drawMenu()
    {
        for (byte i = 0; i < GamesCount; i++)
        {
            Device::display.setCursor(4, 5 + i * 10);

            if (selectedGameID == i)
            {
                Device::display.print(">");
            }

            Device::display.setCursor(12, 5 + i * 10);
            Device::display.print(games[i]->name);
        }
    }

    void displayMenu()
    {
        Device::display.display();
    }
};
