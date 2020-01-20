#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define LEVEL "FluffyMaze1.txt"

static const char START = 's';
static const char FINISH = 'f';
static const char WALL = '*';
static const char PATH = ' ';
static const char PLAYER = 'x';
static const char VOID = ' ';

typedef struct
{
    int x;
    int y;
} location, dimension;

typedef struct
{
    char ** blocks;
    dimension dim;
    location fluffy;
} maze;

maze readMaze();
