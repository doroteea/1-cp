///3.3.Write a modular program which reads student related data for a group,
///namely: name, date of birth, residence address, and prints them in lexicographic order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
    studentType **student = (studentType**)malloc(sizeof(studentType*)*30);
    int i;
    for(i=1; i<=30; i++)
        *student = (studentType*)malloc(sizeof(studentType)*30);

    int nrStudents;
    printf("Input the number of students: ");
    scanf("%d",&nrStudents);

    for(i=1; i<=nrStudents; i++)
    {
        student[i] = readStudent(i);
    }

    compareStudents(student,nrStudents);

    return 0;
}
