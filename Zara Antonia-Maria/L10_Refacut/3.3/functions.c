#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int year;
    int month;
    int day;
} dateType;

typedef struct
{
    char *name;
    dateType birthday;
    char *residenceAdress;
} studentType;

studentType *readStudent(int nr)
{
    studentType *student = (studentType*)malloc(sizeof(studentType)*1);
    student->name = (char*)malloc(sizeof(char)*30);
    student->residenceAdress = (char*)malloc(sizeof(char)*30);

    getchar();
    printf("Input the name of student nr %d: ",nr);
    gets(student->name);
    printf("Input the residence adress of the student nr %d: ",nr);
    gets(student->residenceAdress);
    printf("Input the birthday of the student nr %d as following: ",nr);
    printf("\n\tYear: ");
    scanf("%d",&student->birthday.year);
    printf("\tMonth: ");
    scanf("%d",&student->birthday.month);
    printf("\tDay: ");
    scanf("%d",&student->birthday.day);

    return student;
}

void reverseBirthday(int i, int j, studentType **student)
{
    int aux;
    aux = student[i]->birthday.year;
    student[i]->birthday.year = student[j]->birthday.year;
    student[j]->birthday.year = aux;

    aux = student[i]->birthday.month;
    student[i]->birthday.month = student[j]->birthday.month;
    student[j]->birthday.month = aux;

    aux = student[i]->birthday.day;
    student[i]->birthday.day = student[j]->birthday.day;
    student[j]->birthday.day = aux;
}

void reverseNames(int i, int j, studentType **student)
{
    char *aux = (char*)malloc(sizeof(char)*30);
    strcpy(aux,student[i]->name);
    strcpy(student[i]->name,student[j]->name);
    strcpy(student[j]->name,aux);
}

void reverseAdress(int i, int j, studentType **student)
{
    char *aux = (char*)malloc(sizeof(char)*30);
    strcpy(aux,student[i]->residenceAdress);
    strcpy(student[i]->residenceAdress,student[j]->residenceAdress);
    strcpy(student[j]->residenceAdress,aux);
}

void reverseData(int i, int j, studentType **student)
{
    reverseBirthday(i,j,student);
    reverseNames(i,j,student);
    reverseAdress(i,j,student);
}

void printStudents(int nr, studentType **student)
{
    int i;
    printf("The students in aplhabetical order and their data are:");
    for(i=1; i<=nr; i++)
    {
        printf("\n%s:",student[i]->name);
        printf("\n\tBirthday: %d.%d.%d",student[i]->birthday.day,student[i]->birthday.month,student[i]->birthday.year);
        printf("\n\tResidenceAdress: %s",student[i]->residenceAdress);
    }
}

void compareStudents( studentType **student, int nr)
{
    int i,j;
    for(i=1; i<nr; i++)
    {
        for(j=i; j<=nr; j++)
        {
            if(strcmp(student[i]->name,student[j]->name)>0)
            {
                reverseData(i,j,student);
            }
        }
    }
    printStudents(nr,student);
}
