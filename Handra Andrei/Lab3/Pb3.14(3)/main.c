#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int height,age;
    float idealweight;
    char *sex=(char*)malloc(sizeof(char)*6);
    printf("Give the sex of the person: ");
    gets(sex);
    printf("Give the height and age of the person:");
    scanf("%d %d",&height,&age);
    if(strcmp(sex,"male")==0)
    {
        idealweight=50+0.75*(height-150)+(age-20)/4;
    }
    else
    {
        idealweight=(50+0.75*(height-150)+(age-20)/4)-10;
    }
    printf("The ideal weight is %.2f kg",idealweight);
    return 0;
}
