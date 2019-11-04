#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sizeOfP1, sizeOfP2;
void productOfPolynomials(int *pol1, int *pol2, int *pol3)
{
    int i,j;
    memset(pol3,0,sizeof(int)*(sizeOfP1+sizeOfP2));
    for(i=0; i<sizeOfP1; i++)
    {
        for(j=0; j<sizeOfP2; j++)
        {
            pol3[i+j]=pol3[i+j]+(pol1[i]) *(pol2[j]);
        }
    }

}
int main()
{
    printf("Hello world!\n");
    int i,j;
    scanf("%d %d",&sizeOfP1, &sizeOfP2);
    int *pol1=(int*)malloc(sizeof(int)*sizeOfP1);
    int *pol2=(int*)malloc(sizeof(int)*sizeOfP2);
    int *pol3=(int*)malloc(sizeof(int)*(sizeOfP1+sizeOfP2));
    for(i=0; i<sizeOfP1; i++)
    {
        scanf("%d",&pol1[i]);
    }
    for(j=0; j<sizeOfP2; j++)
    {
        scanf("%d",&pol2[j]);

    }
    productOfPolynomials(pol1,pol2,pol3);
    for(i=0; i<sizeOfP1+sizeOfP2; i++)
    {
        printf("%dx^%d ",pol3[i],i);
    }
    return 0;
}
