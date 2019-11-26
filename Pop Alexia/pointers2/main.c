#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Input the first number %d",a);
    scanf("%d",&a);
    printf("Input the second number %d",b);
    scanf("%d",&b);
     int *p=&a,*q=&b;
    if(*p > *q)
        printf("The maximum value of the two numbers is %d",*p);
    else printf("The maximum value of the two numbers is %d",*q);

    return 0;} /*nu inteleg de ce printeaza si adresa */
