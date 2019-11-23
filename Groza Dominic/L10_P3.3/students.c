#include "students.h"

void initializeStudent(student * s) {
    s->name = (char*) malloc(sizeof(char)*MAX_STUDENT_NAME_LENGTH);
    s->address = (char*) malloc(sizeof(char)*MAX_STUDENT_ADDRESS_LENGTH);
    s->dateOfBirth.day = (int) malloc (sizeof(char)*MAX_STUDENT__DATEOFBIRTH_LENGTH);
    s->dateOfBirth.month = (int) malloc (sizeof(char)*MAX_STUDENT__DATEOFBIRTH_LENGTH);
    s->dateOfBirth.year = (int) malloc (sizeof(char)*MAX_STUDENT__DATEOFBIRTH_LENGTH);
}

student * readStudents(int n)
{
    student * students = (student*)malloc(sizeof(student)*n);
    getchar();
    for(int i=0; i<n; i++)
    {
        initializeStudent(&students[i]); //passing by reference ca sa putem aloca
        getchar();
        printf("Reading student %d\n", i+1);
        printf("Student[%d] name= ",i+1);
        gets(students[i].name);
        puts(students[i].name);
        printf ("Student[%d] address= ",i+1);
        gets(students[i].address);
        puts(students[i].address);
        printf ("Student[%d] date of birth using / delimiters= ",i+1);
        scanf("%d/%d/%d",&students[i].dateOfBirth.day,&students[i].dateOfBirth.month,&students[i].dateOfBirth.year);
    }
    return students;
}