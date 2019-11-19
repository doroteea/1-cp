#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,sum=0,i;
    printf("Introduce two numbers ");

    scanf("%d%d",&num1,&num2);

    for(i=num1; i<=num2; i++)
    {
        if(i%17!=0)
            sum+=i;
    }
    printf("The sum of the numbers between %d and %d not divisible by 17 is %d",num1,num2,sum);
    return 0;
}
