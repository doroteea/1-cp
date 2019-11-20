
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sex;
    float height,age,weight;
    printf("Input sex initial: ");
    scanf("%c",&sex);
    printf("\nInput height: ");
    scanf("%f",&height);
    printf("\nInput age: ");
    scanf("%f",&age);
    weight=50+0.75*(height-150)+(age-20)/4;
    if(sex=='m' || sex=='M')printf("%f",weight);
    if(sex=='f' || sex=='F')printf("%f",weight-10);
    return 0;
}
