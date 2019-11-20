#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

student readStud (student *group, int i)
{
    printf ("name of student#%d: ", i);
    group[i].name = (char*) malloc (sizeof (char) * 35);
    gets (group[i].name);
    printf ("date of birth (day, month, year): ");
    scanf ("%d", &group[i].birthDate.day);
    scanf ("%d", &group[i].birthDate.month);
    scanf ("%d", &group[i].birthDate.year);
    getchar ();
    printf ("residence: ");
    group[i].residence = (char*) malloc (sizeof (char) * 100);
    gets (group[i].residence);
    return group[i];
}

void printStudents (student *group, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf ("%s (%d.%d.%d) - %s\n", group[i].name, group[i].birthDate.day, group[i].birthDate.month, group[i].birthDate.year, group[i].residence);
    }
}

student * sortStudents (student *group, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp (group[i].name, group[j].name) > 0)
            {
                student aux;
                aux = group[i];
                group[i] = group[j];
                group[j] = aux;
            }
        }
    }
    return group;
}
