#include <stdio.h>
#include <stdlib.h>


int nonRecHermite(int n, int x)
{
    int *value=(int*)malloc(sizeof(int)*(n+1));
    value[0]=1;
    value[1]=2*x;

    int i=2;
    for (; i<=n; i++)
    {
        value[i]=2*i*value[i-1] - 2*(i-1)*value[i-2];
    }
    return value[i-1];
}

int Hermite (int n, int x)
{
    if (n==0)
    {
        return 1;
    }
    if (n==1)
    {
        return 2*x;
    }
    return (2*n*Hermite(n-1, x) - 2*(n-1)*Hermite(n-2, x));
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);

    printf("Nonrecursive: %d \n", nonRecHermite(n, x));
    printf("Recursive: %d", Hermite(n, x));

    return 0;
}
