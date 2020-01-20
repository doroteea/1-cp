#include "students.h"

void initializeStudent(student * s) {
    s->name = (char*) malloc(sizeof(char)*MAX_STUDENT_NAME_LENGTH);
    s->address = (char*) malloc(sizeof(char)*MAX_STUDENT_ADDRESS_LENGTH);
}

date readDateOfBirth(int studentNumber) {
    date dateOfBirth;
    printf("Year of birth for student %d\nyear=", studentNumber);
    scanf("%d",&dateOfBirth.year);
    printf("Month of birth for student %d\nmonth=", studentNumber);
    scanf("%d",&dateOfBirth.month);
    printf("Day of the month for student %d\nday=", studentNumber);
    scanf("%d",&dateOfBirth.day);
    return dateOfBirth;
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
        students[i].dateOfBirth = readDateOfBirth(i+1);
    }
    return students;
}
