#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 30
#include "cars.h"
#include  <string.h>
void initializeCar(car *c)
{
    c->brand=(char*)malloc(sizeof(char)*MAX_LENGTH);
    c->owner=(char*)malloc(sizeof(char)*MAX_LENGTH);
    c->color=(char*)malloc(sizeof(char)*MAX_LENGTH);
    c->number=(char*)malloc(sizeof(char)*MAX_LENGTH);

}
int main()
{
    int n;
    printf("Enter number of cars:");
    scanf("%d",&n);
    char *fname=(char*)malloc(sizeof(char)*30);
    printf("Enter file name:");
    gets(fname);
    FILE *f=fopen(fname,"w");
    char*strbuf=(char*)malloc(sizeof(char)*MAX_LENGTH);
    car * cars = (car*) malloc(sizeof(car)*n);
    for(int i=0; i<n; i++)
    {
        initializeCar(&cars[i]);
    }
    int pCount = 0;
    while(fgets(strbuf, MAX_LENGTH, f) != NULL)
    {
        sscanf(strbuf,"%s %s %s %s ",cars[pCount].brand,cars[pCount].owner,cars[pCount].color,cars[pCount].number);
        pCount++;
    }
    fclose(f);

    return 0;
}
