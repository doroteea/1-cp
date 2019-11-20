#include <stdio.h>
#include <stdlib.h>

void readArray(float *a, int dim)
{
    for(int i=0; i<dim; i++)
    {
        scanf("%f",&a[i]);
    }
}

void printArray(float *a, int dim)
{
    for(int i=0; i<dim; i++)
    {
        printf("%.2f ",a[i]);
    }
    printf("\n");
}

void interclasare(float *a, float *b, float *c, int dima, int dimb, int *dimc)
{
    int i=0,j=0;
    while(i < dima && j < dimb)
    {
        if(a[i] < b[j])
        {
            c[(*dimc)++] = a[i++];
        }
        else if(a[i] > b[j])
        {
            c[(*dimc)++] = b[j++];
        }
        else
        {
            c[(*dimc)++] = a[i++];
            j++;
        }
        if(c[*dimc-1] == c[*dimc-2])
            (*dimc)--;
    }
    while(i<dima)
    {
        c[(*dimc)++] = a[i++];
        if(c[*dimc-1] == c[*dimc-2])
            (*dimc)--;
    }
    while(j<dimb)
    {
        c[(*dimc)++] = b[j++];
        if(c[*dimc-1] == c[*dimc-2])
            (*dimc)--;
    }
}

int main()
{
    int n,m,p=0;
    scanf("%d",&n);
    scanf("%d",&m);
    float *x = (float*)malloc(sizeof(float)*n);
    float *y = (float*)malloc(sizeof(float)*m);
    float *z = (float*)malloc(sizeof(float)*(m+n));

    readArray(x,n);
    readArray(y,m);

    interclasare(x,y,z,n,m,&p);

    printArray(x,n);
    printArray(y,m);
    printArray(z,p);
    return 0;
}
