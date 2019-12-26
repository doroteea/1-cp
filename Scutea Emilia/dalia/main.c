#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    printf("n=");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(k=n-i-1; k>=0; k--)
            printf(" ");
        for(j=0; j<=2*i-2; j++)
            printf("4");
        printf("\n");
    }
    return 0;
}
