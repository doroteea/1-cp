#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int Max_Length=100;
int n;

typedef struct
{
    int year,month,day;
} date;

typedef struct
{
    int hour,mins;
} time;

typedef struct
{
    char *name;
    date updateDate;
    time updateTime;
} directory;
