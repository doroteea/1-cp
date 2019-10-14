#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n");
    int age;
    float height,W_man,W_woman;
    char  sex;
    scanf("%c",&sex);
    scanf("%f",&height);
    scanf("%d",&age);
    W_man=50+0.75*(height-150)+(age-20)/4;
    W_woman=W_man-10;
    if(sex=='M')
    {
        printf("ideal weight=:%f",W_man);
    }
    else
    {
        printf("ideal weight=:%f",W_woman);
    }

    return 0;
}
