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

    int numRows = 3;
    int numObjects = 4;

    Target* targets = (Target *)MemAlloc(sizeof(Target)*numRows*numObjects);
    bool* active = (bool *)MemAlloc(sizeof(bool)*numRows*numObjects);

    for (int y = 0; y < numRows; y++)
    {
        int sumWidth = 0;
        for (int x = 0; x < numObjects; x++)
        {
            // int width = GetRandomValue(0,0) + Target::minWidth;
            int width = 200;
            targets[y*numRows+x] = Target(&ball, sumWidth, y*Target::staticHeight, width);
            active[y*numRows+x] = true;
            sumWidth += width;
        }
    }
    

    InitWindow(screenWidth, screenHeight, "Adagio!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        ball.Update();
        player.Update();

        BeginDrawing();
        ClearBackground(darkGreen);
        for (int i = 0; i < numObjects*numRows; i++)
        {
            Target target = targets[i];
            if (active[i])
            {
                target.Draw();
                target.Update();
                active[i] = !target.GetWasHit();
            }
        }  
        player.Draw();
        ball.Draw();

        DrawFPS(screenWidth-50,0);
        DrawText(TextFormat("%d", ball.GetScore()), 10, 10, 25, BLACK);

        EndDrawing();
    }

    MemFree(targets);
    MemFree(active);
    CloseWindow();
    return 0;
}