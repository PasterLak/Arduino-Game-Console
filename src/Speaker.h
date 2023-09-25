#ifndef SPEAKER_H
#define SPEAKER_H

#include <Arduino.h>
#include <Audio.hpp>
#include <Time.h>

class Speaker
{
private:
    uint8_t pin;
    uint16_t pauseBetweenNotes;
    uint16_t noteId;
    Audio* audio = new Audio;


    int wholenote = (60000 * 4) / 180;

    void setup();

public:
    bool isPlaying;
    bool loop;

    Speaker(uint8_t pin);

    void update();

    void play(const Audio& audio);

    void stop();
};

#endif // SPEAKER_H
