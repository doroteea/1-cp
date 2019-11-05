#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[4][4],i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            scanf("%d",&matrix[i][j]);

        }

    }
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(matrix[i][j]%2==0)
            {
                printf("%d",(matrix[i][j])*2);
                printf(" ");
            }else{
            printf("%d",matrix[i][j]);
            printf(" ");}
        }



        printf("\n");
    }

    return 0;
}
