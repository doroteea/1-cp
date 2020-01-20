#include "students.h"

int main()
{
    int n;
    printf("Number of students: ");
    scanf("%d", &n);

    studentData *data = readStudents(n);
    sort(data, n);
    printStudents(data, n);

    return 0;
}
