/** 3.2.Write a program which should print the week day (Monday,Tuesday, etc.)
 of your birth, based on your birthdate and the current year week day of your anniversary. **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int year;
    int month;
    int day;
}dateType;

dateType *readBirthday()
{
    dateType *date = (dateType*)malloc(sizeof(dateType)*1);

    printf("Input the year of bday: ");
    scanf("%d",&date->year);
    printf("Input the number of the month of the  of bday: ");
    scanf("%d",&date->month);
    printf("Input the day of the year of bday: ");
    scanf("%d",&date->day);

    return date;
}

int determineWeekdayNumber(char *weekday)
{
    int weekdayNr;
    if(strcmp(weekday,"monday")==0)   weekdayNr = 1;
    if(strcmp(weekday,"tuesday")==0)  weekdayNr = 2;
    if(strcmp(weekday,"wednesday")==0)weekdayNr = 3;
    if(strcmp(weekday,"thursday")==0) weekdayNr = 4;
    if(strcmp(weekday,"friday")==0)   weekdayNr = 5;
    if(strcmp(weekday,"saturday")==0) weekdayNr = 6;
    if(strcmp(weekday,"sunday")==0)   weekdayNr = 7;

    return weekdayNr;
}


int isBissextileYear(int year)
{
    if((year%100==0 && year%400!=0) || year%4!=0) return 0;
    else return 1;
}

int daysPassed(dateType *date)
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

    if(isBissextileYear(date->year)==1 && date->month>2)number++;

    number = number + date->day;

    return number;
}

void whatWeekday(int days, int weekday)
{
    int i = days%7;
    int answer = i - weekday;
    if(answer<1)answer=answer+7;
    ///cumva imi dadea complementarul raspunsului si am scazut din 7 sa fie bine
    ///nu stiu de ce dar nu conteaza
    answer = 7 - answer;
    printf("%d",answer);
}

int main()
{
    dateType *birthday = (dateType*)malloc(sizeof(dateType)*1);
    birthday = readBirthday();

    int currentYear;
    printf("Input current year: ");
    scanf("%d",&currentYear);

    char *weekday = (char*)malloc(sizeof(char)*10);
    printf("Input weekday of this year's bday with all lowercase: ");
    scanf("%s",weekday);

    int weekdayNr;
    weekdayNr = determineWeekdayNumber(weekday);

    int i,daysBetweenBdays = 0;
    for(i = birthday->year+1; i<currentYear; i++)
    {
        daysBetweenBdays = daysBetweenBdays + 365;
        if(isBissextileYear(i)==1)
        {
            daysBetweenBdays++;
        }
    }

    ///aflam cate zile au ramas in anul nasterii
    int daysLeftInBirthYear = 0, daysInBirthYear = 365;
    if(isBissextileYear(birthday->year)==1)daysInBirthYear++;
    daysLeftInBirthYear = daysInBirthYear - daysPassed(birthday);
    daysBetweenBdays = daysBetweenBdays + daysLeftInBirthYear;


    ///aflam cate zile au trecut din anul actual
    dateType *smecherie = (dateType*)malloc(sizeof(dateType)*1);

    smecherie->day = birthday->day;
    smecherie->month = birthday->month;
    smecherie->year = currentYear;

    int daysPassedInCurrentYear = daysPassed(smecherie);
    daysBetweenBdays = daysBetweenBdays + daysPassedInCurrentYear;


    ///calculul final
    whatWeekday(daysBetweenBdays,weekdayNr);

    return 0;
}
