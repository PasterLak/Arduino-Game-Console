#pragma once
#include <Arduino.h>
#include <functional>

class TimerFunction
{
public:
    TimerFunction(unsigned long interval, std::function<void()> callback)
        : interval_(interval), callback_(callback), last_executed_(millis()) {}

    void update()
    {
        unsigned long current_time = millis();
        if (current_time - last_executed_ >= interval_)
        {
            last_executed_ = current_time;
            if (callback_)
            {
                callback_();
            }
        }
    }

private:
    unsigned long interval_;
    std::function<void()> callback_;
    unsigned long last_executed_;
};

class Timer
{
public:
    Timer()
        : functions_(), last_update_(millis()) {}

    void update()
    {
        for (auto &function : functions_)
        {
            function.update();
        }
        last_update_ = millis();
    }

    void addFunction(unsigned long interval, std::function<void()> callback)
    {
        functions_.emplace_back(interval, callback);
    }

private:
    std::vector<TimerFunction> functions_;
    unsigned long last_update_;
};
