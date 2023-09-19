#pragma once

#include <Arduino.h>
#include "Game.h"

#include "Ship.h"
#include "Submarine.h"
#include "Bomb.h"
#include "Rocket.h"
#include "Sprites.hpp"

#define MAX_BOMBS 10
#define MAX_SUBMARINES 6

class SeaBattle : public Game
{
private:
public:
    int score = 0;
    Ship ship;
    Bomb bombs[MAX_BOMBS];
    Submarine submarines[MAX_SUBMARINES]{{(int8_t)1}, {(int8_t)-1}, {(int8_t)1}, {(int8_t)-1}, {(int8_t)1}, {(int8_t)1}};
    Rocket rockets[MAX_BOMBS];

    int timeToSpawnRocket = 200;
    int timeToSpawnSubmarine = 800;

    SeaBattle(String name, String version) : Game(name, version)
    {
        discription = "In this game you have to prevent your ship from sinking!";
    }

    void awake() override
    {
    }
    void start() override
    {
    }

    void update() override
    {
        Device::button.update();
        Device::joystick.update();

        updateInput();
        ship.update();
        drawSprites();
        drawGUI();

        updateTimers();
    }

    void updateTimers()
    {
        updateSpawnRocketTimer();
        updateSpawnSubmarineTimer();
    }

    void updateSpawnRocketTimer()
    {
        if (timeToSpawnRocket > 0)
        {
            timeToSpawnRocket -= deltaTime;
            if (timeToSpawnRocket < 0)
            {
                timeToSpawnRocket = 0;
            }
        }
    }

    void updateSpawnSubmarineTimer()
    {
        if (timeToSpawnSubmarine > 0)
        {
            timeToSpawnSubmarine -= deltaTime;
            if (timeToSpawnSubmarine <= 0)
            {
                timeToSpawnSubmarine = 0;
            }
        }
        else
        {
            spawnSubmarine();
        }
    }

    void spawnSubmarine()
    {
        for (byte i = 0; i < MAX_SUBMARINES; i++)
        {
            if (!submarines[i].isActive())
            {
                submarines[i].create();
                timeToSpawnSubmarine = 500 + random(0, 7000);
                break;
            }
        }
    }

    void updateInput()
    {
        if (Device::joystick.isMovedDown() || Device::button.isDown())
        {
            shootBomb();
        }

        moveShipWithJoystick();
        wrapShipPosition();
    }

    void shootBomb()
    {
        if (ship.canShot())
        {
            for (byte i = 0; i < MAX_BOMBS; i++)
            {
                if (bombs[i].isActive == false)
                {
                    bombs[i].create(ship.getPositionX());
                    ship.shot();
                    break;
                }
            }
        }
    }

    void moveShipWithJoystick()
    {
        if (Device::joystick.x > 700)
        {
            ship.setPositionX(ship.getPositionX() - ship.getSpeed());
        }
        else if (Device::joystick.x < 300)
        {
            ship.setPositionX(ship.getPositionX() + ship.getSpeed());
        }
    }

    void wrapShipPosition()
    {
        if (ship.getPositionX() <= 0)
        {
            ship.setPositionX(128);
        }
        else if (ship.getPositionX() > 128)
        {
            ship.setPositionX(0);
        }
    }

    void drawSprites()
    {
        Device::display.clearDisplay();
        Device::display.drawBitmap(0, 0, sBackground, 128, 64, WHITE);

        drawShip();
        drawRockets();
        drawBombs();
        drawSubmarines();
    }

    void drawShip()
    {
        Device::display.setCursor(ship.getPositionX(), ship.getPositionY());
        Device::display.drawBitmap(ship.getPositionX() - 16, 5, sShip, 32, 12, WHITE);
    }

    void drawRockets()
    {
        for (byte i = 0; i < MAX_BOMBS; i++)
        {
            if (rockets[i].isActive == true)
            {
                int dis = Vector2Byte::distance(ship.getPosition(), rockets[i].getPosition());

                if (dis < 14 && rockets[i].getPositionY() > 10)
                {
                    Device::display.drawBitmap(rockets[i].getPositionX() - 4, rockets[i].getPositionX() - 2, sExplosion, 8, 8, WHITE);
                    rockets[i].destroy();
                    setDamage();
                }
                else
                {
                    int rocketX = rockets[i].getPositionX();
                    int rocketY = rockets[i].getPositionY();
                    drawRocketSplash(rocketX, rocketY);
                    rockets[i].update();
                    Device::display.drawBitmap(rocketX - 1, rocketY - 4, sRocket, 3, 8, WHITE);
                }
            }
        }
    }

    void drawRocketSplash(int x, int y)
    {
        if (y <= 17 && y > 15)
            Device::display.drawBitmap(x - 2, 10, sSplashSmall, 4, 4, WHITE);

        if (y <= 15 && y > 11)
            Device::display.drawBitmap(x - 4, 6, sSplashMedium, 8, 8, WHITE);

        if (y <= 11 && y > 4)
            Device::display.drawBitmap(x - 4, 6, sSplashBig, 8, 8, WHITE);

        if (y <= 4 && y > 2)
            Device::display.drawBitmap(x - 4, 6, sSplashMedium, 8, 8, WHITE);

        if (y <= 2 && y > 0)
            Device::display.drawBitmap(x - 2, 10, sSplashSmall, 4, 4, WHITE);
    }

    void drawBombs()
    {
        for (byte i = 0; i < MAX_BOMBS; i++)
        {
            if (bombs[i].isActive == true)
            {
                bombs[i].update();

                if (bombs[i].position.y > 57)
                {
                    Device::display.drawBitmap(bombs[i].position.x - 4, bombs[i].position.y - 4, sExplosion, 8, 8, WHITE);
                    bombs[i].destroy();
                }
                else
                {
                    drawBomb(bombs[i]);
                    checkBombCollision(bombs[i]);
                    checkRocketCollision(bombs[i]);
                }
            }
        }
    }

    void drawBomb(Bomb &bomb)
    {
        Device::display.drawBitmap(bomb.position.x - 2, bomb.position.y, sBomb, 4, 4, WHITE);
    }

    void checkBombCollision(Bomb &bomb)
    {
        for (byte j = 0; j < MAX_SUBMARINES; j++)
        {
            if (submarines[j].isActive())
            {
                byte dis = Vector2Byte::distance(submarines[j].position, bomb.position);

                if (dis < 6)
                {
                    Device::display.drawBitmap(bomb.position.x - 4, bomb.position.y - 2, sExplosion, 8, 8, WHITE);
                    submarines[j].destroy();
                    score++;
                    bomb.destroy();
                }
            }
        }
    }

    void checkRocketCollision(Bomb &bomb)
    {
        for (byte j = 0; j < MAX_BOMBS; j++)
        {
            if (rockets[j].isActive)
            {
                byte dis = Vector2Byte::distance(bomb.position, rockets[j].getPosition());

                if (dis < 6)
                {
                    Device::display.drawBitmap(bomb.position.x - 4, bomb.position.y - 2, sExplosion, 8, 8, WHITE);
                    rockets[j].destroy();
                    bomb.destroy();
                }
            }
        }
    }

    void drawSubmarines()
    {
        for (byte i = 0; i < MAX_SUBMARINES; i++)
        {
            if (submarines[i].isActive() == true)
            {
                submarines[i].update();
                drawSubmarine(submarines[i]);
                spawnRocketFromSubmarine(submarines[i]);
            }
        }
    }

    void drawSubmarine(Submarine &submarine)
    {
        if (submarine.direction == 1)
        {
            Device::display.drawBitmap(submarine.position.x - 6, submarine.position.y, sSubmarineRight, 12, 8, WHITE);
        }
        else
        {
            Device::display.drawBitmap(submarine.position.x - 6, submarine.position.y, sSubmarineLeft, 12, 8, WHITE);
        }
    }

    void spawnRocketFromSubmarine(Submarine &submarine)
    {
        if (timeToSpawnRocket == 0)
        {
            for (byte j = 0; j < MAX_BOMBS; j++)
            {
                if (rockets[j].isActive == false)
                {
                    rockets[j].create(submarine.position.x, submarine.position.y);
                    Device::display.drawBitmap(submarine.position.x - 4, submarine.position.y - 8, sSplashMedium, 8, 8, WHITE);
                    timeToSpawnRocket = 200 + random(0, 3000);
                    break;
                }
            }
        }
    }

    void drawGUI()
    {
        for (byte i = 0; i < ship.getHp(); i++)
        {
            Device::display.drawBitmap(0 + (7 * i), 0, sHeart, 5, 5, WHITE);
        }

        if (score < 10)
            Device::display.setCursor(110, 0);
        if (score >= 10 && score < 100)
            Device::display.setCursor(103, 0);
        if (score >= 100 && score < 1000)
            Device::display.setCursor(96, 0);

        Device::display.println("x:" + String(score));
        // Device::display.setCursor(30, 10);
        // Device::display.println("fps: " + String(fps()));

        Device::display.display();
    }

    void setDamage()
    {
        if (ship.getHp() > 0)
            ship.setDamage();

        if (ship.getHp() == 0)
        {
            u_int8_t shipX = ship.getPositionX();
            u_int8_t shipY = ship.getPositionY();

            Device::display.drawBitmap(shipX - 16, 5, sShipDestroyed, 32, 12, WHITE);
            Device::display.drawBitmap(shipX - 8, shipY, sExplosion, 8, 8, WHITE);
            Device::display.drawBitmap(shipX, shipY, sExplosion, 8, 8, WHITE);
            // ship.create();
            score = 0;
            drawGUI();
            quit();
        }
    }

    void quit() override
    {
        ship.setHp(3);
        gameIsStarted = false;
        menuIsOpened = true;
    }
};