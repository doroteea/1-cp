#include "students.h"

void initializeStudent(student * s) {
    s->name = (char*) malloc(sizeof(char)*MAX_STUDENT_NAME_LENGTH);
    s->address = (char*) malloc(sizeof(char)*MAX_STUDENT_ADDRESS_LENGTH);
}

student * readStudents(int n)
{
    student * students = (student*)malloc(sizeof(student)*n);
    getchar();
    for(int i=0; i<n; i++)
    {
        initializeStudent(&students[i]);
        printf("Reading student %d\n", i+1);
        printf("Student[%d] name=",i+1);
        gets(students[i].name);
        puts(students[i].name);
    }
    return students;
}
