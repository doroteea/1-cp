#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int read()
{
    int d;
    printf("Numarul este:\n");
    scanf("%d",&d);
    return d;
}
int * vectorAparitie(int n)
{
    int *av=(int*)malloc(sizeof(int)*10);
    while (n>0)
    {
        int cf=n%10;
        av[cf]++;
        n=n/10;
    }
    return av;
}
void printv(int v[10])
{
    for (int i=0; i<10; i++)
        printf("%d",v[i]);
}
