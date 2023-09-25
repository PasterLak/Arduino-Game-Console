#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <Arduino.h>
#include "Note.hpp"

class Audio
{
public:

    
    uint16_t notesCount;
    
    Audio( const Note* notes, uint16_t notesCount)
    {
      this-> notesCount = notesCount;
      
      this->notes = notes;

    }

    Audio()
    {

    }

    const Note *notes;
    
};

#endif