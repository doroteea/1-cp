#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,n[10];
    float avg ,sum=0 ;
    printf("The numbers are :");
    for(i=0; i<10;i++)
    {
        scanf("%d",&n[i]);
        sum+=n[i];
    }
    avg=sum/10;
    printf("The sum is %.2f and the average is %.2f",sum,avg);
    return 0;
}
