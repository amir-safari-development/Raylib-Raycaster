#include "player.h"

Player player = {{}, {1, 0}};

void DrawPlayer()
{
    DrawCircle(player.pos.x, player.pos.y, PLAYER_RADIUS, RED);
    DrawLine(player.pos.x, player.pos.y, player.pos.x + player.dir.x * 30, player.pos.y - player.dir.y * 30, RED);
}

void InitMobility(float moveSpeed)
{
    float deltaX = 0;
    float deltaY = 0;

    if (IsKeyDown(KEY_W))
    {
        deltaX += player.dir.x * moveSpeed;
        deltaY -= player.dir.y * moveSpeed;
    }
    else if (IsKeyDown(KEY_S))
    {
        deltaY += player.dir.y * moveSpeed;
        deltaX -= player.dir.x * moveSpeed;
    }

    if (IsKeyDown(KEY_D))
    {
        deltaY += player.dir.x * moveSpeed;
        deltaX += player.dir.y * moveSpeed;
    }
    else if (IsKeyDown(KEY_A))
    {
        deltaY -= player.dir.x * moveSpeed;
        deltaX -= player.dir.y * moveSpeed;
    }

    float newX = player.pos.x + deltaX;
    float newY = player.pos.y + deltaY;

    if (WORLD_MAP[(int)player.pos.y / TILE_SIZE][(int)newX / TILE_SIZE] == 0 && newX <= COLUMNS * TILE_SIZE && newX >= 0)
        player.pos.x = newX;

    if (WORLD_MAP[(int)newY / TILE_SIZE][(int)player.pos.x / TILE_SIZE] == 0 && newY <= ROWS * TILE_SIZE && newY >= 0)
        player.pos.y = newY;
}

void InitRotation(float rotSpeed)
{
    double oldDirX = player.dir.x;

    if (IsKeyDown(KEY_UP))
    {
        if (player.dir.x != 0)
        {
            float angle = (player.dir.x > 0 ? 1 : -1) * rotSpeed;
            player.dir.x = player.dir.x * cos(angle) - player.dir.y * sin(angle);
            player.dir.y = oldDirX * sin(angle) + player.dir.y * cos(angle);
        }
    }
    else if (IsKeyDown(KEY_DOWN))
    {
        if (player.dir.x != 0)
        {
            float angle = (player.dir.x < 0 ? 1 : -1) * rotSpeed;
            player.dir.x = player.dir.x * cos(angle) - player.dir.y * sin(angle);
            player.dir.y = oldDirX * sin(angle) + player.dir.y * cos(angle);
        }
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        player.dir.x = player.dir.x * cos(-rotSpeed) - player.dir.y * sin(-rotSpeed);
        player.dir.y = oldDirX * sin(-rotSpeed) + player.dir.y * cos(-rotSpeed);
    }
    else if (IsKeyDown(KEY_LEFT))
    {
        player.dir.x = player.dir.x * cos(rotSpeed) - player.dir.y * sin(rotSpeed);
        player.dir.y = oldDirX * sin(rotSpeed) + player.dir.y * cos(rotSpeed);
    }
}