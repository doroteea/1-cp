#include <stdio.h>
#include <stdlib.h>
#include "student.h"
/*3.3. Write a modular program which reads student related data for a group, namely:
 name, date of birth, residence address, and prints them in lexicographic order. */
int main()
{

    int n;

    printf("Input how many students you'll read:\nn=");

    scanf("%d",&n);

    student * students = readStudents(n);

    studentLexicographicSort(students,n);
    printStudents(students,n);
    return 0;
}
