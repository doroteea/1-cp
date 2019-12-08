#include <stdio.h>
#include <stdlib.h>
int sumofelements(int a[],int n)
{
    int sum=0,i;
    for(i=0; i<n; i++)
    {
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int a[100],i,n,sum;
    printf("Input the number of elements \n");
    scanf("%d",&n);
    printf("Introduce the elements of the array \n");
    for(i=0; i<n; i++)
    {

                scanf("%d",&a[i]);

    }
    sum=sumofelements(a,n);
    printf("The sum of the elements is %d",sum);
    return 0;
}
