#include <stdio.h>
#include <stdlib.h>
/*A correct program seems so elusive that I cannot even be sure if I did it right or I am missing out on something*/
int main()
{
    int number, remainder=0, reversedInteger=0, storingInteger;
    printf("Please input your number: ");   scanf("%d", &number);
    storingInteger=number;
    while(storingInteger!=0)
    {
        remainder= storingInteger % 10;
        reversedInteger= reversedInteger*10 + remainder;
        storingInteger= storingInteger / 10;
    }
    if(number==reversedInteger)
    {
        printf("\n %d is a palindrome", number);
    }
    else
    {
        printf("\n %d is not a palindrome", number);
    }
    return 0;
}
