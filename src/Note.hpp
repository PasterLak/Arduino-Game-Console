#ifndef NOTE_HPP
#define NOTE_HPP
struct Note
{
public:
        uint16_t note;
        uint16_t duration;

        Note(uint16_t note, uint16_t duration)
        {
                this->note = note;
                this->duration = duration;
        }
        Note(uint16_t note)
        {
                this->note = note;
                duration = 0;
        }
};

enum class octave1 : uint16_t
{
        C = 33,
        Cs = 35,
        D = 37,
        Ds = 39,
        E = 41,
        F = 44,
        Fs = 46,
        G = 49,
        Gs = 52,
        A = 55,
        As = 58,
        H = 62
};

enum class octave2 : uint16_t
{
        C = 65,
        Cs = 69,
        D = 73,
        Ds = 78,
        E = 82,
        F = 87,
        Fs = 93,
        G = 98,
        Gs = 104,
        A = 110,
        As = 117,
        H = 123
};

enum class octave3 : uint16_t
{
        C = 131,
        Cs = 139,
        D = 147,
        Ds = 156,
        E = 165,
        F = 175,
        Fs = 185,
        G = 196,
        Gs = 208,
        A = 220,
        As = 233,
        H = 247
};

enum class octave4 : uint16_t
{
        C = 262,
        Cs = 277,
        D = 294,
        Ds = 311,
        E = 330,
        F = 349,
        Fs = 370,
        G = 392,
        Gs = 415,
        A = 440,
        As = 466,
        H = 494
};

enum class octave5 : uint16_t
{
        C = 523,
        Cs = 554,
        D = 587,
        Ds = 622,
        E = 659,
        F = 698,
        Fs = 740,
        G = 784,
        Gs = 831,
        A = 880,
        As = 932,
        H = 988
};

#endif