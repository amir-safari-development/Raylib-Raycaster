#include <stdio.h>
#include "raylib.h"
#include "map.h"
#include "player.h"

int main()
{
    int isPlayerSet = 0;

    InitWindow(COLUMNS * TILE_SIZE, ROWS * TILE_SIZE, "Raycaster");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        BeginDrawing();

        ClearBackground(BLACK);

        DrawMap(&isPlayerSet);

        DrawPlayer();

        InitMobility(BASE_SPEED * deltaTime);

        InitRotation(BASE_ROT_SPEED * deltaTime);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}