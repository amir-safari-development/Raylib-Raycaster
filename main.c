#include <stdio.h>
#include "raylib.h"
#include "map.h"
#include "player.h"

int main()
{
    InitWindow(COLUMNS * TILE_SIZE, ROWS * TILE_SIZE, "Raycaster");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

    }

    CloseWindow();
    return 0;
}