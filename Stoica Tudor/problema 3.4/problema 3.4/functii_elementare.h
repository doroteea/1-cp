//
// Created by stoic on 23 oct. 2019.
//

#ifndef PROBLEMA_LAB_FUNCTII_ELEMENTARE_H
#define PROBLEMA_LAB_FUNCTII_ELEMENTARE_H

#endif //PROBLEMA_LAB_FUNCTII_ELEMENTARE_H

#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if(a>b)
        return b;
    else
        return a;
}

int abs(int a)
{
    if(a>0) return a;
    else return (-a);
}

//void cin_int(int *a)
//{
//    scanf("%d", a);
//}

void coutMessage(char *message)
{
    printf("%s",message);
}

int cinInt()
{
    int i;
    scanf("%d", &i);
    return i;
}

void coutInt(int *a)
{
    printf("%d",a);
}

void reverseIntVec(int *vec, int size)
{
    for(int i=1;i<=size/2;i++)
    {
        swap(&vec[i],&vec[size-i+1]);
    }
}

void cinNextIntMat(int **mat, int size)
{

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void cinNextIntVec(int *vec, int size)
{

    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &vec[i]);
    }
}

void coutIntVec(int *vec, int size)
{

    for (int i = 1; i <= size; i++)
    {
        coutInt(vec[i]);
        sp();
    }
}

void coutCharVec(char *vec, int size)
{

    for (int i = 1; i <= size; i++)
    {
        coutChar(vec[i]);
        sp();
    }
}

/********************************************//**
 *  this function reads the next int array on the line in the vec parameter, when its size is not inputed
 *  and returns the array's size
 ***********************************************/

//int readNextIntVec(int *vec)
//{
//    int a=0,vecSize=0;
//
//    while(scanf("%d", &a) && a!='\n')
//    {
//        vec[++vecSize]=a;
//    }
//
//    return vecSize;
//}

void br()
{
    printf("\n");
}

void sp()
{
    printf(" ");
}

void cinNextCharVec(char *vec, int size)
{
    for (int i = 0; i <= size; i++)
    {
        scanf("%c", &vec[i]);
    }
}

char cinChar(char *a)
{
    char i;
    scanf("%c", a);
    return i;
}

void coutChar(char *a)
{
    printf("%c",a);
}

