#pragma once
#include "ball.h"

class Target
{
public:
    Target(Ball* ball);
    void Update();
    void Draw();

private:
    Ball* refBall;
    int x;
    int y;
    int width;
    int height;
    int radius;
};