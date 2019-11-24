#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int MAX_STUDENT_NAME_LENGTH = 200;
static int MAX_STUDENT_ADDRESS_LENGTH = 200;

typedef struct
{
    int year;
    int month;
    int day;
} date;

typedef struct
{
    char * name;
    date dateOfBirth;
    char * address;
} student;

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

student * readStudents(int n)
{
    int i;
    student * students = (student*)malloc(sizeof(student)*n);
    getchar();
    for(i=0; i<n; i++)
    {
        initializeStudent(&students[i]);
        printf("Reading student %d\n", i+1);
        printf("Student[%d] name=",i+1);
        gets(students[i].name);
        puts(students[i].name);
        students[i].dateOfBirth = readDateOfBirth(i+1);
        printf("Student[%d] address=",i+1);
        getchar();
        gets(students[i].address);
        puts(students[i].address);

    }
    return students;
}

student * lexicographicalOrder(int n,student * students)
{
    student * s=(student*)malloc(sizeof(student)*n);
    getchar();
    initializeStudent(s);
    int i,sort=0;
    while(sort==0)
    {
        sort=1;
        for(i=0; i<n-1; i++)
        {
            if(strcmp(students[i].name,students[i+1].name)>0)
            {
                s[0]=students[i];
                students[i]=students[i+1];
                students[i+1]=s[0];
                sort=0;
            }
        }
    }
    return students;
}

void printStudents(int n,student *s)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("student[%d]\n name: %s\n",i+1,s[i].name);
        printf("date of birth:\nyear:%d\n",s[i].dateOfBirth.year);
        printf("month:%d\n",s[i].dateOfBirth.month);
        printf("day:%d\n",s[i].dateOfBirth.day);
        printf("address: %s\n",s[i].address);
    }
}

int main()
{
    int n;
    printf("Input how many students you'll read:\nn=");
    scanf("%d",&n);
    student * students = readStudents(n);
    student * lexstudents= lexicographicalOrder(n,students);
    printStudents(n,lexstudents);
    return 0;
}
