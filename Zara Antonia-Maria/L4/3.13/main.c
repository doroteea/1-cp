#include <stdio.h>
#include <stdlib.h>

int main()
{
    float v[1001],value;
    int n,i;
    printf("Input the number of elements in the sequence: ");
    scanf("%d",&n);
    printf("\nInput the elements: ");
    for(i=1;i<=n;i++)
    {
        scanf("%f",&v[i]);
    }
    printf("\nInput the value that is to be searched: ");
    scanf("%f",&value);
    i=1;
    while(v[i]<value)
    {
        i++;
    }
    if(v[i]==value)printf("The value %f has been found on position %d",value,i);
                else printf("The value is not in the sequence");
    return 0;
}
