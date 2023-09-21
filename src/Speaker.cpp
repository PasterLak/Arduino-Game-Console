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
        if (pauseBetweenNotes > 0)
        {
            pauseBetweenNotes -= deltaTime;
        }

        if (pauseBetweenNotes <= 0 && noteId < audio.notesCount)
        {
            noTone(pin);
            tone(pin, audio.notes[noteId].note, audio.notes[noteId].duration);

            pauseBetweenNotes = audio.notes[noteId].duration + 50; // Может потребоваться корректировка в зависимости от вашей аппаратуры

            noteId++;

            if (noteId == audio.notesCount)
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

void Speaker::play(Audio audio)
{
    this->audio = audio;
    pauseBetweenNotes = 0;
    noteId = 0;
    isPlaying = true;
}

void Speaker::stop()
{
    noTone(pin);
    noteId = 0;
    pauseBetweenNotes = 0;
    isPlaying = false;
}
