#include <stdio.h>
#include <stdlib.h>

void readPolynom(int *a, int dim) //sirurie vor fi citite in ordine crescatoare a puterilor ex: 3*x^0+x^1 +7*x^2
{
    for(int i=0; i<dim; i++)
    {
        printf("x^%d: ",i);
        scanf("%d",&a[i]);
    }
}

void printPolynom(int *a, int dim)
{
    for(int i=0; i<dim; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void product(int *a, int *b,int *c, int dima, int dimb)
{
    for(int i=0; i<dima; i++)
    {
        for(int j=0; j<dimb; j++)
        {
            c[i+j] = c[i+j]+a[i]*b[j];
        }
    }
}

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int *x = (int*)malloc(sizeof(int)*n);
    int *y = (int*)malloc(sizeof(int)*m);
    int *z = (int*)malloc(sizeof(int)*(n+m));
    for(int i=0; i<n+m-1; i++)
    {
        z[i]=0;
    }
    readPolynom(x,n);
    readPolynom(y,m);
    product(x,y,z,n,m);
    printPolynom(z,n+m-1);
    return 0;
}
