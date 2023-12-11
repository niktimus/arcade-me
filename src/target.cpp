#include "target.h"
#include "ball.h"
#include <raylib.h>

Target::Target(Ball* ball) : refBall(ball)
{
    x = 0;
    y = 0;
    width = 200;
    height = 50;
    radius = 10;
}

void Target::Update()
{
    Rectangle rec = Rectangle();
    rec.x = x;
    rec.y = y;
    rec.width = width;
    rec.height = height;

    Vector2 v = Vector2();
    v.x = refBall->GetX();
    v.y = refBall->GetY();

    if (CheckCollisionCircleRec(v, refBall->GetRadius(), rec))
    {
        refBall->Reflect();
        delete this;
    }
}

void Target::Draw()
{
    DrawCircle(x + radius, y + radius, radius, WHITE); // top left corner
    DrawCircle(x + width - radius, y + radius, radius, WHITE); // top right corner
    DrawCircle(x + radius, y + height - radius, radius, WHITE); // bottom left corner
    DrawCircle(x + width - radius, y + height - radius, radius, WHITE); // bottom right corner

    DrawRectangle(x, y+radius, radius*2, height-radius*2, WHITE); // left plank
    DrawRectangle(x+radius, y, width-radius*2, radius*2, WHITE); // top plank
    DrawRectangle(x+width-radius*2, y+radius, radius*2, height-radius*2, WHITE); // right plant
    DrawRectangle(x+radius, y+height-radius*2, width-radius*2, radius*2, WHITE); // bottom plank
    DrawRectangle(x+radius*2, y+radius*2, width-radius*4, height-radius*4, WHITE);// centre box
}

