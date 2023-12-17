#include "ball.h"
#include <raylib.h>
#include "scores.h"

Ball::Ball()
{
    x = 400;
    y = 300;
    speedX = 5;
    speedY = 5;
    radius = 15;
    bestScore = LoadStorageValue(0);
}

void Ball::Update()
{
    x += speedX;
    y += speedY;

    if (x + radius >= GetScreenWidth() || x - radius <= 0)
        speedX *= -1;

    if (y + radius >= GetScreenHeight())
    {
        if (score > bestScore) {
            SaveStorageValue(0, score);
            bestScore = score;
        }
        gameOver = true;
    }
    
    if (y - radius <= 0)
    {
        speedY *= -1;
    }
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}

int Ball::GetX()
{
    return x;
}

int Ball::GetY()
{
    return y;
}

int Ball::GetRadius()
{
    return radius;
}

void Ball::Reflect()
{
    speedY *= -1;
}

void Ball::IncScore()
{
    score++;
}

int Ball::GetScore()
{
    return score;
}

bool Ball::isGameOver()
{
    return gameOver;
}

int Ball::GetBestScore()
{
    return bestScore;
}