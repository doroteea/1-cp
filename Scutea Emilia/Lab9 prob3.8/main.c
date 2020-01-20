#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int rows,columns,string_length;
    printf("Please input the number of rows:");
    scanf("%d",&rows);
    printf("Please input the number of columns:");
    scanf("%d",&columns);
    printf("Please input the number of string_length:");
    scanf("%d",&string_length);
    char *** string=readString(rows,columns,string_length);
    printf("The strings are:\n");
    printString(string,rows,columns);
    printf("a) The names of the authors in alphabetic order are:\n");
    firstOrder(string,columns,string_length);
    printf("b) The names  of the authors and the titles of their books in order of the publication year are:\n");
    secondOrder(string,rows,columns);
}
