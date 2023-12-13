#include "ball.h"
#include <raylib.h>

Ball::Ball()
{
    x = 400;
    y = 300;
    speedX = 5;
    speedY = 5;
    radius = 15;
}

void Ball::Update()
{
    x += speedX;
    y += speedY;

    if (x + radius >= GetScreenWidth() || x - radius <= 0)
        speedX *= -1;

    if (y + radius >= GetScreenHeight())
    {
        speedY *= -1;
        score -= 100;
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
