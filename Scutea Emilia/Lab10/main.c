#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{

    int n;
    printf("Please insert the number of students:\nn=");
    scanf("%d",&n);
    student *a=readStudents(n);
    lexOrder(a,n);
    printStudents(a,n);

}
