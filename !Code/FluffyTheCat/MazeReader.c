#include "MazeReader.h"

dimension readDimension(FILE * f)
{
    dimension dim;
    fscanf(f, "%d %d\n",&dim.x, &dim.y);
    return dim;
}

maze initializeMaze(dimension dim)
{
    maze m;
    m.dim = dim;
    m.blocks = (char**)malloc(sizeof(char*) * dim.x);
    for(int i=0; i<dim.x; i++)
    {
        m.blocks[i] = (char*) malloc(sizeof(char)*dim.y);
    }

    return m;
}

maze readMaze()
{
    FILE * mazeFile = fopen(LEVEL, "r");
    maze m = initializeMaze(readDimension(mazeFile));

    char block;
    int i=0, j=0;
    while((block = fgetc(mazeFile)) != EOF)
    {
        if(block == '\n')
        {
            i++;
            j=0;
            continue;
        }
        if(block == START)
        {
            m.fluffy.x = i;
            m.fluffy.y = j;
        }

        m.blocks[i][j]=block;
        j++;
    }
    fclose(mazeFile);
    return m;
}
