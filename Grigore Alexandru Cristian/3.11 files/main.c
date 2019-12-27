#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
#define CARS 10

typedef struct
{
    char * brand;
    char * owner;
    char * color;
    char * number;
} garage;

void initializeGarage(garage * car)
{
    car->brand=(char*)malloc(sizeof(char)*MAX_LENGTH);
    car->owner=(char*)malloc(sizeof(char)*MAX_LENGTH);
    car->color=(char*)malloc(sizeof(char)*MAX_LENGTH);
    car->number=(char*)malloc(sizeof(char)*MAX_LENGTH);
}


void displayCarsWithTheSameColor(garage *car,int count,char *carColor)
{
        for(int i=0;i<count;i++)
        {
            if(strstr(carColor,car[i].color)!=NULL)
            {
                printf("%s %s %s %s",car[i].brand,car[i].owner,car[i].color,car[i].number);
            }
        }
}

int main()
{
    FILE *f=fopen("garage.txt","r");
    garage *car=(garage*)malloc(sizeof(garage)*MAX_LENGTH);
    char *strbuf=(char*)malloc(sizeof(char)*MAX_LENGTH);
    for(int i=0;i<CARS;i++)
    {
        initializeGarage(&car[i]);
    }
    int count=0;
    while(fgets(strbuf,MAX_LENGTH,f)!=NULL)
    {
        sscanf(strbuf,"%s %s %s %s",car[count].brand,car[count].owner,car[count].color,car[count].number);
        puts(strbuf);
        char *p=(char*)malloc(sizeof(char)*MAX_LENGTH);
        p=strtok(strbuf,",");
        puts(p);
        while(p)
        {
            strcpy(car[count].color,p);
            p=strtok(NULL,",");
        }
        count++;

    }
    char *carColor=(char*)malloc(sizeof(char)*MAX_LENGTH);
    gets(carColor);
    displayCarsWithTheSameColor(car,count,carColor);

    return 0;
}
