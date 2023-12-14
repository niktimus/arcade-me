#include <raylib.h>
#include "ball.h"
#include "player.h"
#include "target.h"


void allUpdate(Ball* ball, Player* player, int numTargets, Target* targets, bool* active);
void allDraw(Ball *ball, Player *player, int numTargets, Target *targets, bool *active, Color bg);

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

    bool onPlay = false;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE))
            onPlay = !onPlay;
        
        if (onPlay && !ball.isGameOver())
            allUpdate(&ball, &player, numObjects*numRows, targets, active);

        BeginDrawing();
        
        allDraw(&ball, &player, numObjects*numRows, targets, active, darkGreen);

        DrawFPS(GetScreenWidth() - 50, 0);
        
        if (ball.isGameOver()) {
            DrawText("GAME OVER",
                GetScreenWidth() * 0.25, GetScreenHeight() * 0.5, 50, BLACK);
            DrawText(TextFormat("%d", ball.GetScore()),
                GetScreenWidth() * 0.45, GetScreenHeight() * 0.6, 50, BLACK);
            DrawText(TextFormat("BEST: %d", ball.GetBestScore()),
                GetScreenWidth() * 0.35, GetScreenHeight() * 0.7, 50, BLACK);
        }
        else
            DrawText(TextFormat("%d", ball.GetScore()), 10, 10, 25, BLACK);

        if (!ball.isGameOver() && !onPlay)
        {
            DrawText("PAUSE",
                GetScreenWidth() * 0.4, GetScreenHeight() * 0.5, 50, BLACK);
        }

        EndDrawing();
    }

    MemFree(targets);
    MemFree(active);
    CloseWindow();
    return 0;
}

void allUpdate(Ball* ball, Player* player, int numTargets, Target* targets, bool* active)
{
    ball->Update();
    player->Update();
    for (int i = 0; i < numTargets; i++)
    {
        Target target = targets[i];
        if (active[i])
        {
            target.Draw();
            target.Update();
            active[i] = !target.GetWasHit();
        }
    }
}

void allDraw(Ball *ball, Player *player, int numTargets, Target *targets, bool *active, Color bg)
{
    ClearBackground(bg);
    for (int i = 0; i < numTargets; i++)
    {
        Target target = targets[i];
        if (active[i])
        {
            target.Draw();
        }
    }
    player->Draw();
    ball->Draw();
}