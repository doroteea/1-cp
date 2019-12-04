#include "MazeGame.h"

void play(maze m)
{
    printBoard(m);

    int exit = 0;
    while(!exit)
    {
        char direction = getch();
        if(pressedDirectionKey(direction))
        {
            changeFluffyPosition(&m, direction);
        }
        else if(pressedEndGame(direction))
        {
            printf("Exiting game...\n");
            exit = 1;
        }

        if(reachedTheEnd(m))
        {
            system("cls");
            printf("Meow. I reached the end. Purr\n");
            exit = 1;
        }
        else
        {
            printBoard(m);
        }
    }
}

void changeFluffyPosition(maze * m, char direction)
{
    location oldPosition = m->fluffy;
    location newPosition = oldPosition;
    switch(direction)
    {
    case UP:
        newPosition.x = oldPosition.x - 1;
        break;
    case LEFT:
        newPosition.y = oldPosition.y - 1;
        break;
    case DOWN:
        newPosition.x = oldPosition.x + 1;
        break;
    case RIGHT:
        newPosition.y = oldPosition.y + 1;
        break;
    }
    if(newPositionIsValid(newPosition, *m))
    {
        m->blocks[oldPosition.x][oldPosition.y] = PATH;
        m->fluffy = newPosition;
    }
}

void printBoard(maze m)
{
    system("cls");
    m.blocks[m.fluffy.x][m.fluffy.y] = PLAYER;
    for(int i=0; i<m.dim.x; i++)
    {
        for(int j=0; j<m.dim.y; j++)
        {
            location current;
            current.x = i;
            current.y = j;
            if(isWithinRangeOfFluffy(m.fluffy, current))
            {
                printf("%c", m.blocks[i][j]);
            }
            else
            {
                printf("%c", VOID);
            }
        }
        printf("\n");
    }
}

int isWithinRangeOfFluffy(location fluffy, location current)
{
    double dist = sqrt(pow(fluffy.x - current.x, 2) + pow(fluffy.y - current.y, 2));
    return dist < VIEW_DISTANCE;
}

int reachedTheEnd(maze m)
{
    return m.blocks[m.fluffy.x][m.fluffy.y] == FINISH;
}

int newPositionIsValid(location newPosition, maze m)
{
    return (newPosition.x >= 0 && newPosition.x < m.dim.x) && (newPosition.y >= 0 && newPosition.y < m.dim.y)
           && (m.blocks[newPosition.x][newPosition.y] != WALL);
}

int pressedDirectionKey(char direction)
{
    return direction == UP || direction == LEFT || direction == DOWN || direction == RIGHT;
}

int pressedEndGame(char direction)
{
    return direction == END_GAME;
}


