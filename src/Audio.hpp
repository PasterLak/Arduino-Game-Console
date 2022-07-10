#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <Arduino.h>
#include "Note.hpp"

class Audio
{
public:

    
    int notesCount;
    
    Audio( const Note* notes, int notesCount)
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