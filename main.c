#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main()
{
    int n;
    printf ("How many students? n = ");
    scanf ("%d", &n);
    getchar ();
    student *group = (student*) malloc (sizeof (student) * 100);
    for (int i = 0; i < n; i++)
    {
        group[i] = readStud (group, i);
    }
    group = sortStudents (group, n);
    printStudents (group, n);
    return 0;
}

