#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[25], i,n;
    printf(" Input the number of elements to store in the array :");
    scanf("%d",&n);

    printf(" Input %d number of elements in the array :\n",n);
    for(i=0; i<n; i++)
    {
        printf(" element - %d : ",i);
        scanf("%d",v+i);
    }
    printf(" The elements you entered are : \n");
    for(i=0; i<n; i++)
    {
        printf(" element - %d :%d \n",i,*(v+i));
    }
    return 0;
}
