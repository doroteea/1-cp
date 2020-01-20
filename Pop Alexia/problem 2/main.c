#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp1,temp2;
    printf("Introduce the temperatures for yesterday and today \n");
    scanf("%f%f",&temp1,&temp2);
    if(temp1>0){
        printf("Yesterday the temperature was greater than 0 F\n");}
    else
    {printf("Yesterday was very cold ");}
        if (temp2<100)
           {
           printf("Today the temperature is less than 100 F ");}
        else {printf("Today is very hot ");
        }
    return 0;
}
