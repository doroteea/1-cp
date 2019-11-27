#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ONEDEGREE  0.01745329252

int readAngle()
{
    int angle;
    scanf("%d",&angle);
    return angle;
}

int checkAngle(int angle)
{
    while(angle<0 || angle>360)
    {
        printf("\nInvalid input, please enter an angle between 0 and 360 degrees: ");
        angle=readAngle();
    }
    return angle;
}

double convertToReadians(int angle)
{
    float radians=angle*ONEDEGREE;
    return radians;
}

double sine(double radians)
{
    return sin(radians);
}

double cosine(double radians)
{
    return cos(radians);
}

double tangent(double radians)
{
    return sin(radians)/cos(radians);
}

