#include <stdio.h>

int HermiteRecursive_a0(int n)
{
    if (n==0) return 1;
    if (n==1) return 0;
    if (n>1) return 2*n*HermiteRecursive_a0(n-1)-2*(n-1)*HermiteRecursive_a0(n-2);
}

int HermiteRecursive_a1(int n)
{
    if (n==0) return 0;
    if (n==1) return 2;
    if (n>1) return 2*n*HermiteRecursive_a1(n-1)-2*(n-1)*HermiteRecursive_a1(n-2);
}

int main()
{
    int n;
    printf("Please insert value of Hermite polynomial: ");
    scanf("%d", &n);

    printf("%dx , %d", HermiteRecursive_a1(n), HermiteRecursive_a0(n));


    return 0;
}