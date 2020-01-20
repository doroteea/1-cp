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
        scanf("%s",students[i].name);
        //gets(students[i].name);
        puts(students[i].name);
        printf("Student[%d] year=",i+1);
        scanf("%d",&students[i].dateOfBirth.year);
        printf("Student[%d] month=",i+1);
        scanf("%d",&students[i].dateOfBirth.month);
        printf("Student[%d] day=",i+1);
        scanf("%d",&students[i].dateOfBirth.day);
        printf("%d %d %d\n",students[i].dateOfBirth.year,students[i].dateOfBirth.month,students[i].dateOfBirth.day);
    }
    return students;
}

void swap(student *students, int i, int j)
{
    student aux;
    aux = students[i];
    students[i] = students[j];
    students[j] = aux;
}

void print(student *students,int n)
{
    for(int i=0;i<n;i++)
    {
        puts(students[i].name);
        printf("%d %d %d\n",students[i].dateOfBirth.year,students[i].dateOfBirth.month,students[i].dateOfBirth.day);
    }
}

void sort(student *students, int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(students[i].name,students[j].name)>0)
            {
                swap(students,i,j);
            }
        }
    }
}
