#ifndef MAP_H
#define MAP_H

#include "player.h"

#define TILE_SIZE 64
#define ROWS 10
#define COLUMNS 10

extern int WORLD_MAP[ROWS][COLUMNS];

void DrawMap(int *isPlayerSet);

#endif