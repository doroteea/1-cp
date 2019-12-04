#include "MazeReader.h"
#include "math.h"

static const int VIEW_DISTANCE = 12;
static const char UP = 'w';
static const char LEFT = 'a';
static const char DOWN = 's';
static const char RIGHT = 'd';
static const char EXIT = 'e';


void play(maze m);
void changeFluffyPosition(maze * m, char direction);
int isWithinRangeOfFluffy(location fluffy, location current);
void printBoard(maze m);
int newPositionIsValid(location newPosition, maze m);
int reachedTheEnd(maze m);
