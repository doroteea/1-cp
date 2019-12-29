#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool IsValid (int *stack, int k)
{
    for (int i=0; i<k; i++)
    {
        if (stack[i]==stack[k])
        {
            return false;
        }
    }
    return true;
}

void print (int *a, int *stack, int n, FILE *g)
{
    for (int i=0; i<n; i++)
    {
        fprintf(g, "%d ", a[stack[i]]);
    }
    fprintf(g, "\n");
}
void GeneratePermutations(int *a, int *stack, int k, int n, FILE *g)
{
    if (k==n)
    {
        return;
    }
    for (int i=0; i<n; i++)
    {
        stack[k]=i;
        if (IsValid(stack, k))
        {
            if (k==n-1)
            {
                print(a, stack, n, g);
            }
            else
            {
                GeneratePermutations(a, stack, k+1, n, g);
            }
        }
    }
}

int main()
{
    FILE *f=fopen("data.in", "r");

    int n;
    fscanf(f, "%d", &n);
    int *a = (int*)malloc(sizeof(int)*n);

    for (int i=0; i<n; i++)
    {
        fscanf(f, "%d", &a[i]);
    }

    fclose(f);
    FILE *g = fopen("data.out", "w");

    int *stack = (int*)malloc(sizeof(int)*n);
    GeneratePermutations(a, stack, 0, n, g);

    fclose(g);

    return 0;
}
