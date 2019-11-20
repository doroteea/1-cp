#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i;

    printf("Input two numbers");
    scanf("%d%d",&a,&b);
    for(i=a; i<=b; i++)
        if (i%7==2 || i%7==3)
           {
            printf("%d",i);
            printf(" ");}

    return 0;
}
