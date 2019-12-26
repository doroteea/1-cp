typedef struct
{
    int day,month,year;
} date_birth;

typedef struct
{
    char *name[30];
    date_birth date;
    char *address[30];
} student;

student *readStudents(int n);

void printStudents(student *a,int n);

student lexOrder(student *a,int n);
