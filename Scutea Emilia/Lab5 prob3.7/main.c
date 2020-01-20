#include <stdio.h>
#include <stdlib.h>

void findNumberOfDay(int year, int month,int day,int months[12])
{
    int nrOfDay=0;
    int daysRemaining=365;
    if(year%4==0) ///if the year is bissextile
    {
        months[1]++;
        daysRemaining++;
    }
    for(int i=0;i<month-1;i++) ///either use month-1 or start with i from 1
    {
        nrOfDay = nrOfDay + months[i];
    }
    nrOfDay = nrOfDay + day;
    daysRemaining = daysRemaining - nrOfDay;
    printf("The number of the day in the year is %d and the number of days to the end of that year is %d.",nrOfDay,daysRemaining);
}

int main()
{

    int year,month,day;
    printf("Please input the year:\nyear=");
    scanf("%d",&year);
    printf("Please input the month:\nmonth=");
    scanf("%d",&month);
    printf("Please input the day:\nday=");
    scanf("%d",&day);
    int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    findNumberOfDay(year,month,day,months);
}
