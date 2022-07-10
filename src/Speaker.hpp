#pragma once
#include <Arduino.h>
#include <Audio.hpp>
#include <Global.h>

class Speaker
{

private:
    byte pin = 12;
    int pauseBetweenNotes = 0;
    int noteId = 0;
    Audio audio;

    void setup()
    {
        pinMode(pin, OUTPUT);
    }

public:
    bool isPlaying = false;
    bool loop = false;

    Speaker(byte pin)
    {
        this->pin = pin;
        setup();
    }

    void update()
    {

        if (isPlaying)
        {
            if (pauseBetweenNotes > 0)
            {

                pauseBetweenNotes -= deltaTime;
            }

            if (pauseBetweenNotes <= 0 && audio.notesCount > 0)
            {
                noTone(pin);
                tone(pin, (audio.notes[noteId].note), audio.notes[noteId].duration);

                pauseBetweenNotes = audio.notes[noteId].duration * 1.3f;

                noteId++;

                if (noteId == audio.notesCount)
                {
                    stop();
                }
            }
        }
    }

    void play(Audio audio)
    {
        this->audio = audio;
        pauseBetweenNotes = 0;
        noteId = 0;
        isPlaying = true;
    }

    void stop()
    {
        noTone(pin);
        noteId = 0;
        pauseBetweenNotes = 0;
        isPlaying = false;
    }
};