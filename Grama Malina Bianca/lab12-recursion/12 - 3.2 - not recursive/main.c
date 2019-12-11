#include<stdio.h>

struct polynomial
{
    int a1;
    int a0;
};

struct polynomial polynomial[100];

int main()
{
    int n;
    printf("Insert number of Hermite polynomials to be displayed: ");
    scanf("%d", &n);

    polynomial[0].a0=1;
    polynomial[0].a1=0;
    polynomial[1].a0=0;
    polynomial[1].a1=2;

    printf("%d", polynomial[0].a0);
    printf("\n");
    printf("%dx", polynomial[1].a1);
    printf("\n");

    for(int i = 2; i < n; i++)
    {
        polynomial[i].a1=2*i*polynomial[i-1].a1-2*(i-1)*polynomial[i-2].a1;
        polynomial[i].a0=2*i*polynomial[i-1].a0-2*(i-1)*polynomial[i-2].a0;
    }

    for (int i=2;i<n;i++)
    {
        printf("%dx%d", polynomial[i].a1, polynomial[i].a0);
        printf("\n");
    }

    return 0;
}