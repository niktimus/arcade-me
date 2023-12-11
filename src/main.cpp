#include <raylib.h>
#include "ball.h"
#include "player.h"
#include "target.h"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    Ball ball = Ball();
    Player player = Player(&ball);
    Target target = Target(&ball);

    InitWindow(screenWidth, screenHeight, "Adagio!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGreen);
        ball.Update();
        player.Update();
        target.Update();
        player.Draw();
        target.Draw();
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}