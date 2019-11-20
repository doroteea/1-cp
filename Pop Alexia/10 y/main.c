#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x1,x2,y1,y2,gdistance;
    printf("input x1:\n");
    scanf("%f",&x1);
    printf("input y1:\n");
    scanf("%f",&y1);
    printf("input x2\n");
    scanf("%f",&x2);
    printf("input y2\n");
    scanf("%f",&y2);
    gdistance=((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1));
    printf("the distance between the 2 points is %f\n",sqrt(gdistance));

    return 0;
}

