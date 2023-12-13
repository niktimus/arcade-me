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
    void IncScore();
    int GetScore();
    bool isGameOver();

private:
    int x;
    int y;
    int speedX;
    int speedY;
    int radius;
    int score = 0;
    bool gameOver = false;
};