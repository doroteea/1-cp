// Write a recursive program to generate the subsets of k elements of a set A with a total number of
//n elements (i.e. combinations of k elements taken from a total of n elements).

#include <stdio.h>
#include <stdlib.h>


void print (int *stack, int k, FILE *g)
{
    for (int i=0; i<k; i++)
    {
        fprintf(g, "%d ", stack[i]);
    }
    fprintf(g, "\n");
}

void GenerateCombinations(int *a, int *stack, int nrOfElem, int i, int k, int n, FILE *g)
{
    if (nrOfElem==k)
    {
        return;
    }
    for (; i<n; i++)
    {
        stack[nrOfElem]=a[i];
        if (nrOfElem==k-1)
        {
            print(stack, k, g);
        }
        else
        {
            GenerateCombinations(a, stack, nrOfElem+1, i+1, k, n, g);
        }
    }
}

int main()
{
    FILE *f = fopen("data.in", "r");

    int n, k;
    fscanf(f, "%d%d", &n, &k);

    int *a = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++)
    {
        fscanf(f, "%d", &a[i]);
    }

    int *stack = (int*)malloc(sizeof(int)*k);
    FILE *g = fopen("data.out", "w");

    GenerateCombinations(a, stack, 0, 0, k, n, g);
    fclose(g);
    return 0;
}
