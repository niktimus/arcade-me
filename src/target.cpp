#include "target.h"
#include "ball.h"
#include <raylib.h>
#include <stdio.h>

Target::Target()
{
    x = 0;
    y = 0;
    width = minWidth;
    height = staticHeight;
    radius = 10;
    wasHit = false;
}

Target::Target(Ball* ball) : ball(ball)
{
    Target();
    width = 200;
    height = staticHeight;
    wasHit = false;
}

Target::Target(Ball* ball, int x, int y, int width) : ball(ball), x(x), y(y), width(width)
{
    height = staticHeight;
    radius = 10;
    wasHit = false;
}

void Target::Update()
{
    Rectangle rec = Rectangle();
    rec.x = x;
    rec.y = y;
    rec.width = width;
    rec.height = height;

    Vector2 v = Vector2();
    v.x = ball->GetX();
    v.y = ball->GetY();

    if (CheckCollisionCircleRec(v, ball->GetRadius(), rec))
    {
        wasHit = true;
        ball->Reflect();
    }
}

void Target::Draw()
{
    if (!wasHit)
    {
        DrawCircle(x + radius, y + radius, radius, WHITE);                  // top left corner
        DrawCircle(x + width - radius, y + radius, radius, WHITE);          // top right corner
        DrawCircle(x + radius, y + height - radius, radius, WHITE);         // bottom left corner
        DrawCircle(x + width - radius, y + height - radius, radius, WHITE); // bottom right corner

        DrawRectangle(x, y + radius, radius * 2, height - radius * 2, WHITE);                          // left plank
        DrawRectangle(x + radius, y, width - radius * 2, radius * 2, WHITE);                           // top plank
        DrawRectangle(x + width - radius * 2, y + radius, radius * 2, height - radius * 2, WHITE);     // right plant
        DrawRectangle(x + radius, y + height - radius * 2, width - radius * 2, radius * 2, WHITE);     // bottom plank
        DrawRectangle(x + radius * 2, y + radius * 2, width - radius * 4, height - radius * 4, WHITE); // centre box
    }
}

bool Target::GetWasHit()
{
    return wasHit;
}
