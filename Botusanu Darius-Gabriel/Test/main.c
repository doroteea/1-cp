#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, storingVar,n;
    printf("Please input a number from 1 to 10, it will represent the number of terms: "); scanf("%d", &n);
    int sir[10];
    for(i=0;i<n;i++)
    {
        scanf("%d", &sir[i]);
    }
    printf("\nThis is your sequence in increasing order: ");
    for(i=0;i<n;i++)
    {
        if(sir[i]>sir[i+1])
        {
            storingVar=sir[i];
            sir[i]=sir[i+1];
            sir[i+1]=storingVar;
        }
    }
    for(j=0;j<n:j++)
    {
        if(s[i]>s[j]);

    }
    return 0;

}
