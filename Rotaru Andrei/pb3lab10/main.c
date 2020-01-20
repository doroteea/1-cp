#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include "students.h"

int main()
{
    int n;
    printf("Input the number of students read:\nn=");
    scanf("%d",&n);
    student *students=readStudents(n);
    sortLexicographic(students,n);
    printStudents(students,n);
    return 0;
}
