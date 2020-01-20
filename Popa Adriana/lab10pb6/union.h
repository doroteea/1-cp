#include <stdio.h>
#include <stdlib.h>
static float pi=3.14;

typedef struct
{
    float radius;
} circle;

typedef struct
{
    float length,width;
} rectangle;

typedef struct
{
    float length;
} square;

typedef struct
{
    float length,height;
} triangle;

typedef struct
{
    circle C;
    rectangle R;
    square S;
    triangle T;
} Union;

typedef struct
{
    float circleArea,rectangleArea,squareArea,triangleArea;
} Areas;
