#include <stdio.h>
#include <stdlib.h>
int n;

double* mergeVectors(double *x, double *y)
{
    int i=0, j=0, k=0;
    double *z=(double*)malloc(sizeof(double)*2*n);

    while (i<n && j<n)
    {
        if (x[i]<y[j])
        {
            z[k]=x[i];
            k++;
            i++;
        }
        else if (x[i]>y[j])
        {
            z[k]=y[j];
            k++;
            j++;
        }
        else
        {
            z[k]=x[i];
            k++;
            i++;
            while (x[i]==x[i-1] && i<n)
            {
                i++;
            }
            j++;
            while (y[j]==y[j-1] && j<n)
            {
                j++;
            }
        }
    }

    while (i<n)
    {
        z[k]=x[i];
        k++;
        i++;
    }
    while (j<n)
    {
        z[k]=y[j];
        k++;
        j++;
    }

    return z;

}

int main()
{
    scanf("%d", &n);
    double *x=(double*)malloc(sizeof(double)*n);
    double *y=(double*)malloc(sizeof(double)*n);
    double *z=(double*)malloc(sizeof(double)*2*n);

    for (int i=0; i<n; i++)
    {
        scanf("%lf", &x[i]);
    }
    for (int i=0; i<n; i++)
    {
        scanf("%lf", &y[i]);
    }


    z= mergeVectors(x, y);

    for (int i=0; i<2*n; i++)
    {
        printf("%f ", z[i]);
    }

    return 0;
}
