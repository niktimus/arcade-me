#include "player.h"
#include "ball.h"
#include <raylib.h>

Player::Player(Ball* ball) : ball (ball)
{
    // X is horisontal
    // Y is vertical
    // 0 0 is top left corner
    const int screenWidth = 800;
    const int screenHeight = 600;

    x = screenWidth / 2;
    y = screenHeight - 20;
    width = 100;
    radius = 15;
    speedX = 10;

    keyRight = KEY_D;
    keyLeft = KEY_A;
}

void Player::Update()
{
    Move();

    Collide();
}

void Player::Move()
{
    int newX = x;

    if (IsKeyDown(keyLeft))
        newX -= speedX;
    
    if (IsKeyDown(keyRight))
        newX += speedX;

    if (newX + radius + width >= GetScreenWidth() || newX - radius <= 0)
        ;
    else
        x = newX;
}

void Player::Collide()
{
    Rectangle rec = Rectangle();
    rec.x = x - radius;
    rec.y = y - radius;
    rec.width = radius + width + radius;
    rec.height = radius * 2;

    Vector2 v = Vector2();
    v.x = ball->GetX();
    v.y = ball->GetY();

    if (CheckCollisionCircleRec(v, ball->GetRadius(), rec))
        ball->Reflect();
}

void Player::Draw()
{
    DrawCircle(x, y, radius, WHITE);
    DrawRectangle(x, y-radius, width, 2*radius, WHITE);
    DrawCircle(x+width, y, radius, WHITE);
}