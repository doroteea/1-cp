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
        students[i].dateOfBirth=readDateOfBirth(i+1);
        getchar();
        printf("Student[%d] adress: ",i+1);
        gets(students[i].address);
        puts(students[i].address);


    }
    return students;
}
student *sortStudents(student *students,int n)
{
    int i,j;
    student *s=(student*)malloc(sizeof(student)*n);
    getchar();
    initializeStudent(s);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
                if(strcmp(students[i].name,students[j].name)>0)
                    {
                        student aux;
                        aux=students[i];
                        students[i]=students[j];
                        students[j]=aux;
                    }
            }
    }
    return students;
}
void printStudents(student *s,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("student[%d]\n name: %s\n",i+1,s[i].name);
        printf("date of birth:\nyear:%d\n",s[i].dateOfBirth.year);
        printf("month:%d\n",s[i].dateOfBirth.month);
        printf("day:%d\n",s[i].dateOfBirth.day);
        printf("address: %s\n",s[i].address);
    }
}
