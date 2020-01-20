#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[3][3],i,j;
    for (i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d",&matrix[i][j]);
        }

    }
    printf("The secondary diagonal is : \n");
    for(i=0; i<3; i++)
    {
        printf("%d",matrix[i][2-i]);

        printf("\n");
    }
    printf("The  matrix is : \n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d",matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("The primary diagonal is : \n");
    for(i=0; i<3; i++)
    {
        printf("%d",matrix[i][i]);
        printf(" \n");
    }
    return 0;
}
