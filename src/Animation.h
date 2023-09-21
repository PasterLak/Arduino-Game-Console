#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>
#include <avr/pgmspace.h>

class Animation
{
private:
    const unsigned char **frames; // Массив указателей на массивы пикселей кадров
    int frameCount;               // Количество кадров в анимации
    int frameWidth;               // Ширина каждого кадра
    int frameHeight;              // Высота каждого кадра
    int currentFrame;             // Текущий кадр
    int animationSpeed;           // Скорость анимации в миллисекундах между кадрами
    long lastFrameTime;           // Время последнего кадра
    bool isPlaying;               // Флаг проигрывания анимации
    int posX;                     // Позиция X анимации
    int posY;                     // Позиция Y анимации

public:
    Animation(const unsigned char **frames, int frameCount, int frameWidth, int frameHeight, int animationSpeed, int posX = 0, int posY = 0);
    void update();
    void play();
    void stop();
    void setPosition(int x, int y);
    bool isFinished();
};

#endif // ANIMATION_H
