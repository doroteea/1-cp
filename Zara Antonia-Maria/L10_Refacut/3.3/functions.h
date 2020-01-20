#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int year;
    int month;
    int day;
} dateType;

typedef struct
{
    char *name;
    dateType birthday;
    char *residenceAdress;
} studentType;

studentType *readStudent(int nr);
void reverseBirthday(int i, int j, studentType **student);
void reverseNames(int i, int j, studentType **student);
void reverseAdress(int i, int j, studentType **student);
void reverseData(int i, int j, studentType **student);
void printStudents(int nr, studentType **student);
void compareStudents( studentType **student, int nr);
