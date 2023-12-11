#pragma once

class Ball
{
public:
    Ball();
    void Update();
    void Draw();
    int GetX();
    int GetY();
    int GetRadius();
    void Reflect();

private:
    int x;
    int y;
    int speedX;
    int speedY;
    int radius;
};