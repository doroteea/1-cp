#include "MazeReader.h"
#include "math.h"
#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'
#define END_GAME 'e'

static const int VIEW_DISTANCE = 3;

void play(maze m);
void printBoard(maze m);
int isWithinRangeOfFluffy(location fluffy, location current);
int reachedTheEnd(maze m);
void changeFluffyPosition(maze * m, char direction);
int newPositionIsValid(location newPosition, maze m);
int pressedDirectionKey(char direction);
int pressedEndGame(char direction);
