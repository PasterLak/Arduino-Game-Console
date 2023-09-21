#ifndef SPEAKER_H
#define SPEAKER_H

#include <Arduino.h>
#include <Audio.hpp>
#include <Time.h>

class Speaker
{
private:
    byte pin;
    int pauseBetweenNotes;
    int noteId;
    Audio audio;

    void setup();

public:
    bool isPlaying;
    bool loop;

    Speaker(byte pin);

    void update();

    void play(Audio audio);

    void stop();
};

#endif // SPEAKER_H
