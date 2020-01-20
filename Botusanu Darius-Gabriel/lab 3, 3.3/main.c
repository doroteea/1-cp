#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.c"
#define ONEDEGREE  0.01745329252

int main()
{
    printf("Please input the value of an angle  in degrees (from 0 to 360): ");
    int angle=checkAngle(readAngle());
    printf("\nThis is the value of sine(%d)=%2.f",angle,sine(convertToReadians(angle)));
    printf("\nThis is the value of cosine(%d)=%2.f",angle,cosine(convertToReadians(angle)));
    printf("\nThis is the value of tangent(%d)=%2.f",angle,tangent(convertToReadians(angle)));
    return 0;
}

