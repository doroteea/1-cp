#include <stdio.h>
#include <stdlib.h>

int main()
{
    float c1, w1,c2,w2, result;
    printf("the weight of item 1 is :\n");
    scanf("%lf",&w1);
    printf("the number if item 1 is :\n");
    scanf("%lf",&c1);
    printf("the weight of item 2 is :\n");
    scanf("%lf",&w2);
    printf("the number of item 2 is :\n");
    scanf("%lf",&c2);
    result = ((w1*c1)+(w2*c2))/(c1+c2);
    printf("the average value= %f",result);


    return 0;
}
