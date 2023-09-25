#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>
#include <avr/pgmspace.h>

class Animation
{
private:
    const unsigned char **frames; 
    int frameCount;               
    int frameWidth;               
    int frameHeight;             
    int currentFrame;            
    int animationSpeed;          
    long lastFrameTime;          
    bool isPlaying;              
    int posX;                    
    int posY;                   

public:
    Animation(const unsigned char **frames, int frameCount, int frameWidth, int frameHeight, int animationSpeed, int posX = 0, int posY = 0);
    void update();
    void play();
    void stop();
    void setPosition(int x, int y);
    bool isFinished();
};

#endif // ANIMATION_H
