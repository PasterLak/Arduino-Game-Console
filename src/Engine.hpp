#pragma once

#include "Sprites.hpp"
#include "Device.hpp"

static uint8_t selectedGameID;
static bool gameIsStarted;
static bool menuIsOpened = false;

const uint8_t GamesCount = 8;

#include "Game.h"
#include "SeaBattle.hpp"
#include "Minecraft.hpp"
#include "Pubg.hpp"
#include "Debug.hpp"

static Game *games[GamesCount]{
    new SeaBattle("Sea Battle", "0.9"),
    new Minecraft("Minecraft", "0.1"),
    new Minecraft("GTA 8Bit demo", "0.3"),
    new Minecraft("Mario", "0.3"),
    new Minecraft("Spacebox", "0.3"),
    new Minecraft("Lightmare", "0.3"),
    new Pubg("PUBG", "0.3"),
    new Debug("Debug", "0.1")};

#include "ConsoleMenu.hpp"

static ConsoleMenu menu;

class Engine
{

private:
    short logoTime = 2000;

public:
    Engine()
    {
        gameIsStarted = false;
        selectedGameID = 0;
        gameIsStarted = false;
    }

    void start()
    {

        Device::display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
        Device::display.clearDisplay();
        Device::display.setTextSize(1);
        Device::display.setTextColor(WHITE);
    }

    void update()
    {
        
        if (logoTime > 0)
        {
            Device::display.clearDisplay();
            Device::display.drawBitmap(0, 0, sLogo, 128, 64, WHITE);
            Device::display.display();

            logoTime -= deltaTime;
        }
        if (logoTime < 0)
        {
            Device::display.clearDisplay();
            logoTime = 0;
            menuIsOpened = true;
        }

        if (menuIsOpened && !gameIsStarted)
        {
            menu.draw();
        }

        if (gameIsStarted)
        {
            games[selectedGameID]->update();
            games[selectedGameID]->draw();
        }
    }

    void startGame(uint8_t gameID)
    {
        if(gameID >= GamesCount) return;

        gameIsStarted = true;
        menuIsOpened = false;
        games[gameID]->awake();
        games[gameID]->start();
    }
};
