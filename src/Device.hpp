#pragma once

#include <input/Button.h>
#include "input/Joystick.h"
#include <Speaker.h>
#include "Adafruit_I2CDevice.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"

const uint8_t SCREEN_WIDTH = 128;
const uint8_t SCREEN_HEIGHT = 64;

#define OLED_ADDRESS 0x3C

class Device
{
private:
public:
    static Button button;
    static Joystick joystick;
    static Speaker dynamic;
    static Adafruit_SSD1306 display;

    Device()
    {
       
    }

    static void updateInput()
    {
        joystick.update();
        button.update();
    }
};

Button Device::button(7);
Joystick Device::joystick(10,9, false, true);

Speaker Device::dynamic(8);
Adafruit_SSD1306 Device::display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
