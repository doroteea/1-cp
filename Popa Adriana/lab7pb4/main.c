#include <stdio.h>
#include <stdlib.h>

void intercl(float* a,float* b,int n,int m)
{
    int i,j,k;
    float *c=(int*)(malloc(sizeof(int)*(m+n)));
    i=0;
    j=0;
    k=0;
    while(i<n&&j<m)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            if(a[i]>b[j])
            {
                c[k++]=b[j++];
            }
            else
            {
                c[k++]=a[i++];
                j++;
            }
        }
    }
    while(i<n)
    {
        c[k++]=a[i++];
    }
    while(j<m)
    {
        c[k++]=b[j++];
    }
    for(i=0; i<k; i++)
        printf(" %f ,",c[i]);
}

int main()
{
    int n,m,i;
    printf("input length of the vector: ");
    scanf("%d",&n);
    float *a=(int*)(malloc(sizeof(int)*n));
    printf("input elements of the vector: ");
    for(i=0; i<n; i++)
        scanf("%f",&a[i]);

    printf("input length of the vector: ");
    scanf("%d",&m);
    float *b=(int*)(malloc(sizeof(int)*m));
    printf("input elements of the vector: ");
    for(i=0; i<m; i++)
        scanf("%f",&b[i]);

    intercl(a,b,n,m);
    return 0;
}
