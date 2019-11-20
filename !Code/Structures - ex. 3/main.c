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
    student a;
    a.address = (char*) malloc(sizeof(char)*100);
    gets(a.address);
    puts(a.address);
    return 0;
}
