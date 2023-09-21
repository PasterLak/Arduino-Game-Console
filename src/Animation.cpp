#include "animation.h"

Animation::Animation(const unsigned char **frames, int frameCount, int frameWidth, int frameHeight, int animationSpeed, int posX, int posY)
    : frames(frames), frameCount(frameCount), frameWidth(frameWidth), frameHeight(frameHeight), animationSpeed(animationSpeed), posX(posX), posY(posY)
{
    currentFrame = 0;
    isPlaying = false;
    lastFrameTime = 0;
}

void Animation::update()
{
    if (isPlaying)
    {
        long currentTime = millis();
        if (currentTime - lastFrameTime >= animationSpeed)
        {
            lastFrameTime = currentTime;
            currentFrame = (currentFrame + 1) % frameCount;
        }
    }
}

void Animation::play()
{
    isPlaying = true;
    currentFrame = 0;
    lastFrameTime = millis();
}

void Animation::stop()
{
    isPlaying = false;
}

void Animation::setPosition(int x, int y)
{
    posX = x;
    posY = y;
}

bool Animation::isFinished()
{
    return currentFrame == frameCount - 1 && !isPlaying;
}
