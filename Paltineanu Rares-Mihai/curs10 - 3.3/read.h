#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {

    int day;
    int month;
    int year;
}birthday;

typedef struct {

    char *name;
    char *address;
    birthday dateOfBirth;

}student;

void read(student *g, int n);

void write(student *g, int n);

void lexicographicSort(student *g, int n);

void initialize(student *g, int n);
