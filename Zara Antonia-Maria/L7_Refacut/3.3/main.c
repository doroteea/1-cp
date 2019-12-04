#include <stdio.h>
#include <stdlib.h>

double *citire(int nrElements)
{
    int i=0;
    double *p = (double*)malloc(sizeof(double)*nrElements);
    for(i=0; i<nrElements; i++)
    {
        scanf("%lf",&p[i]);
    }
    return p;
}

void sortare(double *p, int nrElements)
{
    int i,j;
    for(i=0; i<nrElements-1; i++)
    {
        for(j=i; j<=nrElements-1; j++)
        {
            if(p[i]>p[j])
            {
                double aux;
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
}

void afisare(double *p, int nrElements)
{
    int i;
    for(i=0; i<nrElements; i++)
    {
        printf("%0.2lf ",p[i]);
    }
}

int main()
{
    int nrElements;
    printf("Input the number of elements: ");
    scanf("%d",&nrElements);

    double *p = (double*)malloc(sizeof(double)*nrElements);

    p = citire(nrElements);
    sortare(p,nrElements);
    afisare(p,nrElements);

    return 0;
}
