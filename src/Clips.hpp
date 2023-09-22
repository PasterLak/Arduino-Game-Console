#pragma once
#include <Audio.hpp>

const Note kkk[39] PROGMEM = {
    Note{392, 350}, Note{392, 350}, Note{392, 350},
    Note{311, 250}, Note{466, 100}, Note{392, 350}, Note{311, 250},
    Note{466, 100}, Note{392, 700}, Note{587, 350}, Note{392, 350},
    Note{587, 350}, Note{622, 250}, Note{466, 100}, Note{369, 350},
    Note{311, 250}, Note{466, 100}, Note{392, 700}, Note{784, 350}, Note{392, 250},
    Note{392, 100}, Note{784, 350}, Note{739, 250}, Note{698, 100}, Note{659, 100},
    Note{622, 100}, Note{659, 450}, Note{415, 150}, Note{554, 350}, Note{523, 250},
    Note{493, 100}, Note{466, 100}, Note{440, 100}, Note{466, 450}, Note{311, 150},
    Note{369, 350}, Note{311, 250}, Note{466, 100}, Note{392, 750}};

const Note kkk2[13] PROGMEM = {
    Note{int(octave5::E), 8}, Note{int(octave5::E), 8},Note{int(octave4::Fs),4},
    Note{int(octave4::Gs), 4},Note{int(octave5::Cs), 8}, Note{int(octave4::H), 8},
    Note{int(octave4::D), 4},Note{int(octave4::E), 4},Note{int(octave4::H), 8},
    Note{int(octave4::A), 8},Note{int(octave4::Cs), 4},Note{int(octave4::E), 4},
    Note{int(octave4::A), 2}
};

const Audio StarWars(
    kkk,
    39);
const Audio Nokia(
    kkk2,
    13);

