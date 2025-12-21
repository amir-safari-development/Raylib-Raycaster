#ifndef PLAYER_H
#define PLAYER_H

#include <math.h>
#include "raylib.h"
#include "map.h"

#define BASE_SPEED 200
#define BASE_ROT_SPEED 2.5f
#define PLAYER_RADIUS 10

typedef struct
{
    Vector2 pos;
    Vector2 dir;
} Player;

extern Player player;

void DrawPlayer();

void InitMobility(float moveSpeed);

void InitRotation(float rotSpeed);

#endif