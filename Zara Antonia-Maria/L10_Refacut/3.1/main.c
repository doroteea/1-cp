/** 3.1.Using the structure type to store a date (year, month, day),
write a program to display the number of the day in a year,
and the number of days to the end of that year.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int year;
    int month;
    int day;
} dateType;

int isBissextileYear( dateType *date)
{
    if((date->year%100==0 && date->year%400!=0) || date->year%4!=0) return 0;
    else return 1;
}

dateType *readDate()
{
    dateType *date = (dateType*)malloc(sizeof(dateType)*1);

    printf("Input the year: ");
    scanf("%d",&date->year);
    printf("Input the number of the month of the year: ");
    scanf("%d",&date->month);
    printf("Input the day of the year: ");
    scanf("%d",&date->day);

    return date;
}

void calculateDayNumber(dateType *date)
{
    int number = 0, i;
    for(i=1; i<=date->month; i++)
    {
        if(i==2) number = number + 31;
        if(i==3) number = number + 28;
        if(i==4) number = number + 31;
        if(i==5) number = number + 30;
        if(i==6) number = number + 31;
        if(i==7) number = number + 30;
        if(i==8) number = number + 31;
        if(i==9) number = number + 31;
        if(i==10)number = number + 30;
        if(i==11)number = number + 31;
        if(i==12)number = number + 30;
    }

    if(isBissextileYear(date)==1 && date->month>2)number++;

    number = number + date->day;

    printf("%d",number);
}

int main()
{
    dateType *date = (dateType*)malloc(sizeof(dateType)*1);
    date = readDate();
    calculateDayNumber(date);
    return 0;
}
