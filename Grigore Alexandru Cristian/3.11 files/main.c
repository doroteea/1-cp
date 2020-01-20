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

void sort(garage *car,int count)
{
    char *aux=(char*)malloc(sizeof(char)*MAX_LENGTH);
    for(int i=0;i<count;i++)
    {
        for(int j=i+1;j<count;j++)
        {
            if(strcmp(car[i].owner,car[j].owner)>0)
                {
                    strcpy(aux,car[i].owner);
                    strcpy(car[i].owner,car[j].owner);
                    strcpy(car[j].owner,aux);
                }
        }
    }
    for(int i=0;i<count;i++)
    {
        puts(car[i].owner);
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
        strcpy(car[count].brand,strtok(strbuf,","));
        strcpy(car[count].owner,strtok(NULL,","));
        strcpy(car[count].color,strtok(NULL,","));
        strcpy(car[count].number,strtok(NULL,","));
        puts(car[count].brand);
        puts(car[count].owner);
        puts(car[count].color);
        puts(car[count].number);
        count++;

    }
    char *carColor=(char*)malloc(sizeof(char)*MAX_LENGTH);
    gets(carColor);
    displayCarsWithTheSameColor(car,count,carColor);
    sort(car,count);
    fclose(f);
    return 0;
}
