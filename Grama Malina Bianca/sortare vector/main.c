#include <stdio.h>

int main()
{
    int n,v[100],i,j,aux;
    printf("Number of elements n= ");
    scanf("%d", &n);
    printf("Unordered sequence: ");
    for (i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    for (i=0;i<n-1;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (v[i]>v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }

    printf("Ordered sequence: \n");

    for (i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }

    return 0;
}