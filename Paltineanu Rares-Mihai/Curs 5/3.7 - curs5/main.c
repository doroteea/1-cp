/**Given three positive integers, representing a year, a month and a day-of-the-month respectively,
write a function to compute the number of the day in the year, and the number of days to the end of that year
*/
#include <stdio.h>
#include <stdlib.h>
int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int nrOfDays(int y, int m, int d) {

    int nr = 0;
    for(int i = 1; i < m; i++) {
        nr += months[i];
    }
    nr += d;
    return nr;
}

void printfdate(int m, int d) {

    switch(d)
    {
        case 1: printf("The number of the 1st of "); break;
        case 2: printf("The number of the 2nd of"); break;
        case 3: printf("The number of the 3rd of"); break;
        default: printf("The number of the %dth of", d);
    }

    switch(m)
    {
        case 1: printf(" January "); break;
        case 2: printf(" February "); break;
        case 3: printf(" March "); break;
        case 4: printf(" April "); break;
        case 5: printf(" May "); break;
        case 6: printf(" June "); break;
        case 7: printf(" July "); break;
        case 8: printf(" August "); break;
        case 9: printf(" September "); break;
        case 10: printf(" October "); break;
        case 11: printf(" November "); break;
        case 12: printf(" December "); break;
    }
}

int main()
{
    int year, month, day; scanf("%d %d %d", &year, &month, &day);
    if(year % 100 == 0 && year & 400 == 0 || (year % 4 ==0 && year % 400 != 0)) {
        months[2]++;
        printf("The year %d is bissextile.\n", year);
    }
    printfdate(month, day); printf("is %d.\n", nrOfDays(year, month, day));

    if(months[2] == 29) {
        printf("The number of days to the end of the year %d is %d.", year, 366 - nrOfDays(year, month, day));
    }
    else {
        printf("The number of days to the end of the year %d is %d.", year, 365 - nrOfDays(year, month, day));
    }
    return 0;
}
