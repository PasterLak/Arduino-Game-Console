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
        for (uint8_t slotId = 0; slotId < 6; slotId++)
        {
            drawSlot(slotId);
        }
    }


    void drawSlot(uint8_t slotId)
    {
        Device::display.setCursor(4, 5 + slotId * 10);

        byte delta = selectedGameID % 6;

        if (delta == slotId)
        {
            Device::display.print(">");
        }

        Device::display.setCursor(12, 5 + slotId * 10);

        if (selectedGameID < 6)
            Device::display.print(games[slotId]->name);
        else
        {
            byte x = slotId + (selectedGameID - delta);

            if (x < GamesCount)
                Device::display.print(games[x]->name);
        }
    }

    void displayMenu()
    {
        Device::display.display();
    }
};
