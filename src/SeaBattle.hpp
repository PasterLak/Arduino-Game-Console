#pragma once

#include <Arduino.h>
#include "Game.hpp"

#include "Ship.hpp"
#include "Submarine.hpp"
#include "Bomb.hpp"
#include "Rocket.hpp"
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
    Submarine submarines[MAX_SUBMARINES]{{(int8_t)1}, {(int8_t)-1}, {(int8_t)1}, {(int8_t)-1}, {(int8_t)1},  {(int8_t)1}};
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

        if (timeToSpawnRocket > 0)
        {
            timeToSpawnRocket -= deltaTime;

            if (timeToSpawnRocket < 0)
            {
                timeToSpawnRocket = 0;
            }
        }

        if (timeToSpawnSubmarine > 0)
        {
            timeToSpawnSubmarine -= deltaTime;

            if (timeToSpawnSubmarine <= 0)
            {
                timeToSpawnSubmarine = 0;
            }
        }

        if (timeToSpawnSubmarine == 0)
        {
            for (byte i = 0; i < MAX_SUBMARINES; i++)
            {
                if (submarines[i].isActive() == false)
                {
                    submarines[i].create();
                    timeToSpawnSubmarine = 500 + random(0, 7000);
                    break;
                }
            }
        }
    }

    void updateInput()
    {
        if (Device::joystick.isMovedDown() || Device::button.isDown())
        {
            if (ship.canShot)
            {
                for (byte i = 0; i < MAX_BOMBS; i++)
                {
                    if (bombs[i].isActive == false)
                    {
                        bombs[i].create(ship.position.x);
                        ship.shot();

                        break;
                    }
                }
            }
        }

        if (Device::button.isDown())
        {
        }

        if (Device::joystick.x > 700)
            ship.position.x = (uint8_t)(ship.position.x - ship.getSpeed());
        if (Device::joystick.x < 300)
            ship.position.x = (uint8_t)(ship.position.x + ship.getSpeed());

        if (ship.position.x <= 0)
            ship.position.x = 128;
        else if (ship.position.x > 128)
            ship.position.x = 0;
    }

    void drawSprites()
    {

        Device::display.clearDisplay();

        Device::display.drawBitmap(0, 0, sBackground, 128, 64, WHITE);

        Device::display.setCursor(ship.position.x, ship.position.y);

        Device::display.drawBitmap(ship.position.x - 16, 5, sShip, 32, 12, WHITE);

        for (byte i = 0; i < MAX_BOMBS; i++)
        {
            if (rockets[i].isActive == true)
            {

                int dis = Vector2Byte::distance(ship.position, rockets[i].position);

                if (dis < 14 && rockets[i].position.y > 10)
                {
                    Device::display.drawBitmap(rockets[i].position.x - 4, rockets[i].position.x - 2, sExplosion, 8, 8, WHITE);
                    rockets[i].destroy();
                    setDamage();
                }
                else
                {
                    if (rockets[i].position.y <= 17 && rockets[i].position.y > 15)
                        Device::display.drawBitmap(rockets[i].position.x - 2, 10, sSplashSmall, 4, 4, WHITE);

                    if (rockets[i].position.y <= 15 && rockets[i].position.y > 11)
                        Device::display.drawBitmap(rockets[i].position.x - 4, 6, sSplashMedium, 8, 8, WHITE);

                    if (rockets[i].position.y <= 11 && rockets[i].position.y > 4)
                        Device::display.drawBitmap(rockets[i].position.x - 4, 6, sSplashBig, 8, 8, WHITE);

                    if (rockets[i].position.y <= 4 && rockets[i].position.y > 2)
                        Device::display.drawBitmap(rockets[i].position.x - 4, 6, sSplashMedium, 8, 8, WHITE);

                    if (rockets[i].position.y <= 2 && rockets[i].position.y > 0)
                        Device::display.drawBitmap(rockets[i].position.x - 2, 10, sSplashSmall, 4, 4, WHITE);

                    rockets[i].update();
                    Device::display.drawBitmap(rockets[i].position.x - 1, rockets[i].position.y - 4, sRocket, 3, 8, WHITE);
                }
            }
            if (bombs[i].isActive == true)
            {
                bombs[i].update();

                if (bombs[i].position.y > 57)
                {
                    Device::display.drawBitmap(bombs[i].position.x - 4, bombs[i].position.y - 4, sExplosion, 8, 8, WHITE);
                    bombs[i].destroy();
                }

                if (bombs[i].isActive)
                {
                    Device::display.drawBitmap(bombs[i].position.x - 2, bombs[i].position.y, sBomb, 4, 4, WHITE);

                    for (byte j = 0; j < MAX_SUBMARINES; j++)
                    {
                        if (submarines[j].isActive())
                        {
                            byte dis = Vector2Byte::distance(submarines[j].position, bombs[i].position);

                            if (dis < 6)
                            {
                                Device::display.drawBitmap(bombs[i].position.x - 4, bombs[i].position.y - 2, sExplosion, 8, 8, WHITE);
                                submarines[j].destroy();
                                score++;
                                bombs[i].destroy();
                            }
                        }
                    }
                }
                if (bombs[i].isActive)
                {
                    for (byte j = 0; j < MAX_BOMBS; j++)
                    {
                        if (rockets[j].isActive)
                        {
                            byte dis = Vector2Byte::distance(bombs[i].position, rockets[j].position);

                            if (dis < 6)
                            {
                                Device::display.drawBitmap(bombs[i].position.x - 4, bombs[i].position.y - 2, sExplosion, 8, 8, WHITE);
                                rockets[j].destroy();
                                bombs[i].destroy();
                            }
                        }
                    }
                }
            }
        }
        for (byte i = 0; i < MAX_SUBMARINES; i++)
        {
            if (submarines[i].isActive() == true)
            {
                submarines[i].update();

                if (submarines[i].isActive())
                {
                    if (submarines[i].direction == 1)
                    {
                        Device::display.drawBitmap(submarines[i].position.x - 6, submarines[i].position.y, sSubmarineRight, 12, 8, WHITE);
                    }
                    else
                        Device::display.drawBitmap(submarines[i].position.x - 6, submarines[i].position.y, sSubmarineLeft, 12, 8, WHITE);

                    if (timeToSpawnRocket == 0)
                    {
                        for (byte j = 0; j < MAX_BOMBS; j++)
                        {
                            if (rockets[j].isActive == false)
                            {
                                rockets[j].create(submarines[i].position.x, submarines[i].position.y);
                                Device::display.drawBitmap(submarines[i].position.x - 4, submarines[i].position.y - 8, sSplashMedium, 8, 8, WHITE);
                                timeToSpawnRocket = 200 + random(0, 3000);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    void drawGUI()
    {
        for (byte i = 0; i < ship.hp; i++)
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
        if (ship.hp > 0)
            ship.setDamage();

        if (ship.hp == 0)
        {
            Device::display.drawBitmap(ship.position.x - 16, 5, sShipDestroyed, 32, 12, WHITE);
            Device::display.drawBitmap(ship.position.x - 8, ship.position.y, sExplosion, 8, 8, WHITE);
            Device::display.drawBitmap(ship.position.x, ship.position.y, sExplosion, 8, 8, WHITE);
            //ship.create();
            score = 0;
            drawGUI();
            quit();
        }
    }

    void quit() override
    {
        ship.hp = 3;
        gameIsStarted = false;
        menuIsOpened = true;
    }



};