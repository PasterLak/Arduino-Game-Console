#pragma once

#include <input/Button.hpp>
#include "input/Joystick.h"
#include <Speaker.hpp>
#include "Adafruit_I2CDevice.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"

const byte SCREEN_WIDTH = 128;
const byte SCREEN_HEIGHT = 64;

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
};

Button Device::button(7);
Joystick Device::joystick;
Speaker Device::dynamic(12);
Adafruit_SSD1306 Device::display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

