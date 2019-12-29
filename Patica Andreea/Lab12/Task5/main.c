///3.5. Write a recursive program to generate the Cartesian product (product set, direct product, cross
///product) of n sets.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LENGTH 100


void print (char *stack, int n, FILE *g)
{
    for (int i=0; i<n; i++)
    {
        fprintf(g, "%c ", stack[i]);
    }
    fprintf(g, "\n");
}

void CartesianProduct (char **set, char *stack, int k, int n, FILE *g)
{
    if (k>=n)
    {
        return;
    }
    for (int i=0; i<n; i++)
    {
        stack[k]=set[k][i];
        if (k==n-1)
        {
            print(stack, n, g);
        }
        else
        {
            CartesianProduct(set, stack, k+1, n, g);
        }
    }
}
int main()
{

    FILE *f = fopen("data.in", "r");

    int n;
    fscanf(f, "%d\n", &n);

    char **set = (char**)malloc(sizeof(char*)*n);
    for (int i=0; i<n; i++)
    {
        set[i] = (char*)malloc(sizeof(char)*MAX_LENGTH);
        fgets(set[i], MAX_LENGTH, f);
    }

    fclose(f);
    FILE *g = fopen("data.out", "w");

    char *stack=(char*)malloc(sizeof(char)*n);
    CartesianProduct(set, stack, 0, n, g);

    fclose(g);

    return 0;
}
