#include "students.h"


void initialize(studentData *d)
{
    d->name=(char*)malloc(sizeof(char)*100);
    d->address=(char*)malloc(sizeof(char)*100);
}

studentData *readStudents(int n)
{
    studentData *data = (studentData*)malloc(sizeof(studentData)*n);
    getchar();
    printf("Enter data for students!\n");

    for (int i=0; i<n; i++)
    {
        initialize(&data[i]);

        printf("Name student %d:\n", i+1);
        scanf("%s", data[i].name);

        printf("Date of birth for student %d:\n", i+1);
        scanf("%d%d%d", &data[i].dateOfBirth.day, &data[i].dateOfBirth.month, &data[i].dateOfBirth.year);

        printf("Address for student %d:\n", i+1);
        scanf("%s", data[i].address);

    }

    return data;
}

void swap (studentData *a, studentData *b)
{
    studentData *aux = (studentData*)malloc(sizeof(studentData));
    *aux=*a;
    *a=*b;
    *b=*aux;
}

void sort (studentData *data, int n)
{
    bool isSorted;
    do
    {
        isSorted=true;
        for (int i=0; i<n-1; i++)
        {
            if (strcmp(data[i].name, data[i+1].name)>0)
            {
                swap(data+i,  data+i+1);
                isSorted=false;
            }
        }
    }while (!isSorted);
}


void printStudents(studentData *data, int n)
{
    printf("Students in alphabetical order:\n");
    for (int i=0; i<n; i++)
    {
        printf("%s ", data[i].name);
        printf("%d %d %d ", data[i].dateOfBirth.day, data[i].dateOfBirth.month, data[i].dateOfBirth.year);
        printf("%s\n", data[i].address);
    }
}
