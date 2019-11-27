typedef struct
{
    int day, month, year;
} date;

typedef struct
{
    char *name, *residence;
    date birthDate;
} student;

student readStud (student *group, int i);
void printStudents (student *group, int n);
student * sortStudents (student *group, int n);
