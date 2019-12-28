#include "student.h"

void initializeStudent(student * s)
{
    s->name = (char*) malloc(sizeof(char)*MAX_STUDENT_NAME_LENGTH);
    s->address = (char*) malloc(sizeof(char)*MAX_STUDENT_ADDRESS_LENGTH);
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
void studentLexicographicSort(student *Array,int n)
{
    student aux;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            if(strcmp(Array[i].name,Array[j].name)>0)
            {
                aux=Array[i];
                Array[i]=Array[j];
                Array[j]=aux;
            }
        }
    }

}
void printStudents(student *Array,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%s born in %d %d %d and lives on %s \n",Array[i].name,Array[i].dateOfBirth.day,Array[i].dateOfBirth.month,Array[i].dateOfBirth.year,Array[i].address);
    }

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
        scanf("%s",&students[i].name);
        printf("Student[%d] date of birth=\n",i+1);
        students[i].dateOfBirth = readDateOfBirth(i+1);
        printf("Student[%d] address=",i+1);
        scanf("%s",&students[i].address);
        // puts(students[i].name);
    }
    return students;
}
