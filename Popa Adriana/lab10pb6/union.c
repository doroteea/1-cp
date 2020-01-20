#include "union.h"

Union readElements()
{
    Union U;
    printf("give the radius of the circle:\n r= ");
    scanf("%f",&U.C.radius);
    printf("give the length and width of rectangle:\nlength= ");
    scanf("%f",&U.R.length);
    printf("\nwidth=");
    scanf("%f",&U.R.width);
    printf("give the length of square:\nlength=");
    scanf("%f",&U.S.length);
    printf("give the length and the height of triangle:\nlength=");
    scanf("%f",&U.T.length);
    printf("height=");
    scanf("%f",&U.T.height);
    return U;
}

Areas calculateAreas(Union U)
{
    Areas A;
    A.circleArea= U.C.radius*U.C.radius*pi;
    A.rectangleArea = U.R.length*U.R.width;
    A.squareArea=U.S.length*U.S.length;
    A.triangleArea=U.T.height*U.T.length;

    return A;
}

void printAreas(Areas A)
{
    printf("\nThe circle area is: %f",A.circleArea);
    printf("\nThe rectangle area is: %f",A.rectangleArea);
    printf("\nThe square area is: %f",A.squareArea);
    printf("\nThe triangle area is: %f",A.triangleArea);
}
