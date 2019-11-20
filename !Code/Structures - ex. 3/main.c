#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    printf("Hello world!\n");
    return 0;
}
