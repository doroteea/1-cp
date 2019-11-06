#include <stdio.h>
#include <stdlib.h>

int main()
{
    char id[10];
    double value, salary;
    int hour;
    printf("input the workers ID \n:");
    scanf("%s",&id);
    printf("input the workers wage/h:\n");
    scanf("%lf",&value);
    printf("input the workers hours");
    scanf("%d",&hour);
    salary=value*hour;
    printf("employees id %s and salary %lf",id,salary);




    return 0;
}
