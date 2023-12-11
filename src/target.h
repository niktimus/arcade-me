#pragma once
#include "ball.h"

class Target
{
public:
    Target(Ball* ball);
    Target(Ball* ball, int x, int width);
    void Update();
    void Draw();

private:
    Ball* ball;
    int x;
    int y;
    int width;
    int height;
    int radius;
};