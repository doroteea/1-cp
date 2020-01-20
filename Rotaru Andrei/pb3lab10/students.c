#include "students.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initializeStudent(student *s)
{
    s->name=(char*)malloc(sizeof(char)*MAX_STUDENT_NAME_LENGTH);
    s->residence=(char*)malloc(sizeof(char)*MAX_STUDENT_RESIDENCE_LENGTH);
}

void printStudents(student *v,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nStudent %d\nName: %s\n",i+1,v[i].name);
        printf("Birth: %d.%d.%d\n",v[i].dateOfBirth.day,v[i].dateOfBirth.month,v[i].dateOfBirth.year);
        printf("Residence: %s\n\n",v[i].residence);
    }
}

void sortLexicographic(student *v,int n)
{
    char *aux=(char*)malloc(sizeof(char)*MAX_STUDENT_NAME_LENGTH);
    for(int i=0; i<n-1; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(strcmp(v[i].name,v[j].name)>0)
            {
                strcpy(aux,v[i].name);
                strcpy(v[i].name,v[j].name);
                strcpy(v[j].name,aux);

            }
        }
    }

}

date readDateOfBirth(int studentNumber)
{
    date dateOfBirth;
    printf("Year of birth for student %d\nyear=", studentNumber);
    scanf("%d",&dateOfBirth.year);
    printf("Month of birth for student %d\nmonth=", studentNumber);
    scanf("%d",&dateOfBirth.month);
    printf("Day of the month for student %d\nday=", studentNumber);
    scanf("%d",&dateOfBirth.day);
    return dateOfBirth;
}

student *readStudents(int n)
{
    student * students = (student*)malloc(sizeof(student)*n);
    for(int i=0; i<n; i++)
    {
        initializeStudent(&students[i]);
        printf("Reading student %d\n", i+1);
        printf("Student[%d] name=",i+1);
        getchar();
        gets(students[i].name);
        students[i].dateOfBirth = readDateOfBirth(i+1);
        printf("Student[%d] residence=",i+1);
        getchar();
        gets(students[i].residence);
    }
    return students;
}
