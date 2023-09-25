#include "speaker.h"

Speaker::Speaker(byte pin)
{
    this->pin = pin;
    setup();
    isPlaying = false;
    loop = false;
}

void Speaker::setup()
{
    pinMode(pin, OUTPUT);
}

void Speaker::update()
{
    if (isPlaying)
    {
        //Serial.println("playing");
        if (pauseBetweenNotes > 0)
        {
            pauseBetweenNotes -= deltaTime;
        }

        if (pauseBetweenNotes <= 0 && noteId < audio->notesCount)
        {
            //Serial.println(noteId);
            noTone(pin);
            int noteDuration = (wholenote) / audio->notes[noteId].duration;
            tone(pin, audio->notes[noteId].note, noteDuration *0.9f );

            pauseBetweenNotes = noteDuration ; 

            noteId++;

            if (noteId == audio->notesCount)
            {
                if (loop)
                {
                    noteId = 0;
                }
                else
                {
                    stop();
                }
            }
        }
    }
}

void Speaker::play(const Audio& audio)
{
    *this->audio = audio;
    pauseBetweenNotes = 0;
    noteId = 0;
    isPlaying = true;

    //Serial.println("START");
}

void Speaker::stop()
{
    noTone(pin);
    noteId = 0;
    pauseBetweenNotes = 0;
    isPlaying = false;
}
