#pragma once
#include "ball.h"

class Target
{
public:
    Target();
    Target(Ball* ball);
    Target(Ball* ball, int x, int y, int width);
    void Update();
    void Draw();
    bool GetWasHit();
    static const int minWidth = 50;
    static const int staticHeight = 50;

private:
    Ball* ball;
    int x;
    int y;
    int width;
    int height;
    int radius;
    bool wasHit;
};