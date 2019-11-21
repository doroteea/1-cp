#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
}date;

typedef struct
{
    char *address;
    char *name;
    date dateOfBirth;
}studentData;

studentData *readStudents(int n);
void swap (studentData *a, studentData *b);
void sort (studentData *data, int n);
void printStudents(studentData *data, int n);
