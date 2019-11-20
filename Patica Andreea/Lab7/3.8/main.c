#include <stdio.h>

int main()
{
    int rank1, rank2;
    printf("Insert rank for 1st polynomial!\n");
    scanf("%d", &rank1);
    int *c1=(int*)malloc(sizeof(int)*(rank1+1));
    printf("Insert coefficients!\n");
    for (int i=0; i<=rank1; i++)
    {
        scanf("%d", &c1[i]);
    }


    printf("Insert rank for 2nd polynomial!\n");
    scanf("%d", &rank2);
    int *c2=(int*)malloc(sizeof(int)*(rank2+1));
    printf("Insert coefficients!\n");
    for (int i=0; i<=rank2; i++)
    {
        scanf("%d", &c2[i]);
    }

    int rank3 = rank2+rank1;
    int *c3=(int*)malloc(sizeof(int)*(rank3));

    for (int i=0; i<=rank3; i++)
    {
        c3[i]=0;
    }

    for (int i=0; i<=rank1; i++)
    {
        for (int j=0; j<=rank2; j++)
        {
            c3[i+j]+=(c1[i])*(c2[j]);
        }
    }

    printf("The polynomial is:\n");
    for (int i=0; i<=rank3; i++)
    {
        printf("%d*x^%d ", c3[i], i);
    }

    return 0;
}
