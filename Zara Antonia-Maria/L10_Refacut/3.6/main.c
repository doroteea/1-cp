///3.6.Using the union type containing the elements needed to represent circles, rectangles, squares,
///    and triangles write a function to compute the area of the corresponding geometric figure

///stiu sa fac si cu union dar e putin mai mult de scris in functii si nu vr

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    double value1;
    double value2;
    char *name;
}shapeType;

double circleArea(shapeType *shape)
{
    double area = 2*3.14;

    printf("Input the radius of the circle: ");
    scanf("%lf",&shape->value1);
    area = area * shape->value1;

    return area;
}

double rectangleArea(shapeType *shape)
{
    double area = 1;

    printf("Input the height of the rectangle: ");
    scanf("%lf",&shape->value1);
    area = area * shape->value1;

    printf("Input the length of the rectangle: ");
    scanf("%lf",&shape->value2);
    area = area * shape->value2;

    return area;
}

double squareArea(shapeType *shape)
{
    double area = 1;

    printf("Input the length of the square: ");
    scanf("%lf",&shape->value1);
    area = area * shape->value1 * shape->value1;

    return area;
}

double triangleArea(shapeType *shape)
{
    double area = 1;

    printf("Input the height of the triangle: ");
    scanf("%lf",&shape->value1);
    area = area * shape->value1;

    printf("Input the length of the base of the triangle: ");
    scanf("%lf",&shape->value2);
    area = area * shape->value2;

    return area/2;
}

void calculateArea (shapeType *shape)
{
    double area;

    if(strcmp(shape->name,"circle")==0)    area = circleArea(shape);
    if(strcmp(shape->name,"rectangle")==0) area = rectangleArea(shape);
    if(strcmp(shape->name,"square")==0)    area = squareArea(shape);
    if(strcmp(shape->name,"triangle")==0)  area = triangleArea(shape);

    printf("\nThe area of the %s is: %lf",shape->name,area);
}

int main()
{
    shapeType *shape = (shapeType*)malloc(sizeof(shapeType)*1);
    shape->name = (char*)malloc(sizeof(char)*15);

    printf("Input name of shape with lowercase letters: ");
    scanf("%s",shape->name);

    calculateArea(shape);

    return 0;
}
