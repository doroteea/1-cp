#include <stdio.h>
#include <stdlib.h>
int sumofnum(int num1, int num2)
{
    int sum ;
    sum=num1+num2;
    return sum;
}
float avgofnum( int num1, int num2)
{
    float avg;
    avg=((float)(num1)+(float)(num2))/2;
    return avg;
}

int main()
{
    int num1,num2;
    int sum;
    float avg;
    printf("Introduce the first number %d",num1);
    scanf("%d",&num1);
    printf("Introduce the second number %d",num2);
    scanf("%d",&num2);
    sum=sumofnum(num1,num2);
    avg=avgofnum(num1,num2);
    printf("The sum is %d\n",sum );
    printf("The average is %f",avg);

    return 0;
}
