#include <stdio.h>
#include <stdlib.h>

static int MAX_STUDENT_NAME_LENGTH = 200;
static int MAX_STUDENT_ADDRESS_LENGTH = 200;

typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct {
    char * name;
    date dateOfBirth;
    char * address;
} student;

student * readStudents(int n);
