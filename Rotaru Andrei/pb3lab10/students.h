#include <stdio.h>
#include <stdlib.h>

static int MAX_STUDENT_NAME_LENGTH = 200;
static int MAX_STUDENT_RESIDENCE_LENGTH = 200;

typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    char *name;
    date dateOfBirth;
    char *residence;
} student;

student *readStudents(int n);
void printStudents(student *v,int n);
void sortLexicographic(student *v,int n);
