#pragma once

#include <Arduino.h>
#include "Game.h"
#include "extentions/Trigger2D.h"
#include "Speaker.h"
#include "Clips.hpp"


class Pubg : public Game
{
private:

    u_int8_t minX = 0, minY = 0;
    u_int8_t maxX = 128, maxY = 64;
    Trigger2D trigger{minX,minY,maxX,maxY};
    u_int8_t x = Device::display.width() / 2;
    u_int8_t y = Device::display.height() / 2;
    

    float time = 0;
public:
    Pubg(String name, String version) : Game(name, version)
    {

    }

    void awake() override final
    {
        Device::display.clearDisplay();
    }
   
    void start() override final
    {
        Device::dynamic.play(Nokia);
        Serial.println(String(minX) + "/" + String(minY) + " - " + String(maxX) + "/" + String(maxY));
    }
    void update() override final
    {
        Device::dynamic.update();
        Device::display.clearDisplay();

        if(Device::button.isDown()) quit();
        time += getSeconds();

        if(((uint16_t)time) >= 2)
        {
            time = 0;
            if(minX < (u_int8_t)50) minX = minX + 2;
            if(minY < (u_int8_t)25) minY++;

            if(maxX > 78) maxX = maxX - 2;
            if(maxY > 39) maxY--;

            trigger.setSize(minX, minY, maxX, maxY);

        
        }
        
        if(Device::joystick.x > 700) x--;
        if(Device::joystick.x < 300) x++;
        if(Device::joystick.y > 700) y--;
        if(Device::joystick.y < 300) y++;

        

        if(x<= 0) x = 128;
        else if (x > 128) x = 0;

        if(y<= 0) y = 64;
        else if (y > 64) y = 0;

        Device::display.drawCircle(x,y,3, WHITE);

        
        Device::display.drawRect(minX, minY, maxX - minX, maxY - minY, WHITE);
        //Device::display.drawRect(50, 25, 78-50, 39-25, WHITE);
        //Device::display.drawRect(0,20,10,10, WHITE);
        
        Device::display.setCursor(5, 5);
        Device::display.println(String(time));

        trigger.update(x,y);

        if(trigger.isActive && trigger.isInside(x,y))
        {
            
            Device::display.drawCircle(30,30,3, WHITE);
        }

        Device::display.display();
    }

    void draw() override final
    {

    }

    void quit() override
    {
         minX = 0, minY = 0;
         maxX = 128, maxY = 64;

         time = 0;

         Game::quit();
    }
};