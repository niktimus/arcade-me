#pragma once
#include "ball.h"

class Player
{
public:
    Player(Ball* ball);
    void Update();
    void Draw();

private:
    Ball* ball;
    int keyLeft;
    int keyRight;
    int x;
    int y;
    int width;
    int speedX;
    int radius;

    void Move();
    void Collide();
};