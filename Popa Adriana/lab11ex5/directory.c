#include "directory.h"

void initializeDirectory(directory *a)
{
    a->name=(char*)(malloc(sizeof(char*)*Max_Length));
}

directory *readDirectory()
{
    FILE *f;
    f=fopen("directory.txt","r");
    directory *d=(directory*)(malloc(sizeof(directory*)*Max_Length));

    int i=0;
    char *p=(char*)(malloc(sizeof(char*)*Max_Length));
    char *strbuf=(char*)(malloc(sizeof(char*)*Max_Length));

    while(fgets(strbuf,Max_Length,f)!=NULL)
    {
        puts(strbuf);
        initializeDirectory(&d[i]);
        p=strtok(strbuf," ");
        strcpy(d[i].name,p);
        p=strtok(NULL," ");
        d[i].updateDate.year=atoi(p);
        p=strtok(NULL," ");
        d[i].updateDate.month=atoi(p);
        p=strtok(NULL," ");
        d[i].updateDate.day=atoi(p);
        p=strtok(NULL," ");
        d[i].updateTime.hour=atoi(p);
        p=strtok(NULL," ");
        d[i].updateTime.mins=atoi(p);
        i++;
    }
    n=i;
    fclose(f);
    return d;
}

void printDirectory(directory *d)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nName:%s\nUpdate date: %d/%d/%d\nUpdate time: %d:%d\n",d[i].name,d[i].updateDate.year,d[i].updateDate.month,d[i].updateDate.day,d[i].updateTime.hour,d[i].updateTime.mins);
    }
}

void swapp(directory a,directory b)
{
    directory aux;
    initializeDirectory(&aux);
    aux=a;
    a=b;
    b=aux;
}

directory *sortByName(directory *d)
{
    int i,ok;
    ok=0;
    while(ok==0)
    {
        ok=1;
        for(i=0; i<n-1; i++)
        {
            if(strcmp(d[i].name,d[i+1].name)>1);
            {
                swapp(d[i],d[i+1]);
                ok=0;
            }
        }
    }
    return d;
}

directory *sortByDate(directory *d)
{
    directory aux;
    initializeDirectory(&aux);
    int i,ok;
    ok=0;
    while(ok==0)
    {
        ok=1;
        for(i=0; i<n; i++)
        {
            if(d[i].updateDate.year>d[i+1].updateDate.year)
            {
                ok=0;
                swapp(d[i],d[i+1]);
            }
            else
            {
                if(d[i].updateDate.year==d[i+1].updateDate.year)
                {
                    if(d[i].updateDate.month>d[i+1].updateDate.month)
                    {
                        ok=0;
                        swapp(d[i],d[i+1]);
                    }
                    else
                    {
                        if(d[i].updateDate.month==d[i+1].updateDate.month)
                        {
                            if(d[i].updateDate.day>d[i+1].updateDate.day)
                            {
                                ok=0;
                                swapp(d[i],d[i+1]);
                            }
                            else
                            {
                                if(d[i].updateDate.day==d[i+1].updateDate.day)
                                {
                                    if(d[i].updateTime.hour>d[i+1].updateTime.hour)
                                    {
                                        ok=0;
                                        swapp(d[i],d[i+1]);
                                    }
                                    else
                                    {
                                        if(d[i].updateTime.hour==d[i+1].updateTime.hour)
                                        {
                                            if(d[i].updateTime.mins>d[i+1].updateTime.mins)
                                            {
                                                ok=0;
                                                swapp(d[i],d[i+1]);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return d;
}
