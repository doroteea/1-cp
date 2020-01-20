#include "header.h"

int b2;
int main()
{
    int a;
    printf("Please input the number you want to convert:\na=");
    scanf("%d",&a);
    b2=readBaseb2(b2);
    printInBase(a,b2);
}
