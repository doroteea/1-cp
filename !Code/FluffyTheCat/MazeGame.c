#include "MazeGame.h"

void play(maze m)
{
    printBoard(m);

    int exit = 0;
    while(!exit)
    {
        char move = getch();
        switch(move)
        {
        case 'w':
            changeFluffyPosition(&m, UP);
            break;
        case 'a':
            changeFluffyPosition(&m, LEFT);
            break;
        case 's':
            changeFluffyPosition(&m, DOWN);
            break;
        case 'd':
            changeFluffyPosition(&m, RIGHT);
            break;
        case 'e':
            exit = 1;
            break;
        default:
            printf("N/A\n");
            break;
        }
        if(reachedTheEnd(m))
        {
            system("cls");
            printf("Meow. I reached it. Purr\n");
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
    location newPosition;
    switch(direction)
    {
    case 'w':
        newPosition.x = oldPosition.x - 1;
        newPosition.y = oldPosition.y;
        break;
    case 'a':
        newPosition.x = oldPosition.x;
        newPosition.y = oldPosition.y - 1;
        break;
    case 's':
        newPosition.x = oldPosition.x + 1;
        newPosition.y = oldPosition.y;
        break;
    case 'd':
        newPosition.x = oldPosition.x;
        newPosition.y = oldPosition.y + 1;
        break;
    }
    if(newPositionIsValid(newPosition, *m))
    {
        m->blocks[oldPosition.x][oldPosition.y] = PATH;
        m->fluffy = newPosition;
    }
}

int newPositionIsValid(location newPosition, maze m)
{
    return (newPosition.x>=0 && newPosition.x <m.dim.x) && (newPosition.y >= 0 && newPosition.y < m.dim.y)
           &&(m.blocks[newPosition.x][newPosition.y] != WALL);
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
                printf("%c",m.blocks[i][j]);
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
