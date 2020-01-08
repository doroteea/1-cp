#include <stdio.h>
#include <stdlib.h>
#include "students.h"

int main()
{
    int n;
    printf("Input how many students you'll read:\nn=");
    scanf("%d",&n);
    student * students = readStudents(n);
    sort(students,n);
    print(students,n);
    return 0;
    return 0;
}
