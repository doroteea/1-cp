#include <stdio.h>
#include <stdlib.h>

int main()
{   float *a=(float*)malloc(sizeof(float)*10);
    float *b=(float*)malloc(sizeof(float)*10);
    float *c=(float*)malloc(sizeof(float)*20);
    int i,j,k;
    for(i=0;i<10;i++)
        scanf("%f",&a[i]);
    for(i=0;i<10;i++)
        scanf("%f",&b[i]);
    i=0;j=0;k=0;
    while(i<10&&j<10)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else if(a[i]>b[j])
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<10)
    {
        c[k]=a[i];
        i++;
        k++;
    }

    while(j<10)
    {
        c[k]=b[j];
        j++;
        k++;
    }
    for(i=0;i<20;i++)
        printf("%f ",c[i]);


    return 0;
}
