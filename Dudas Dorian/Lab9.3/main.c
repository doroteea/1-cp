#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * code;
    char * name;
    char * unit;
    int amount;
    float pricePerUnit;
} itemList;


int main()
{
    FILE * f;

    f = fopen("list.txt","r");
    char * item = (char*) malloc(sizeof(char)*200);
    itemList * object = (itemList*)malloc(sizeof(itemList)*200);
    for(int i=0; i<200; i++)
        {
            object[i].code = (char*) malloc(sizeof(char)*200);
            object[i].name = (char*) malloc(sizeof(char)*200);
            object[i].unit = (char*) malloc(sizeof(char)*200);
        }
    int i=0;
    while(fgets(item, 200, f)!=NULL)
    {

        sscanf(item, "%s %s %s %d %f", object[i].code, object[i].name, object[i].unit, &object[i].amount, &object[i].pricePerUnit);
        printf("%s,%s,%s,%d,%f\n", object[i].code, object[i].name, object[i].unit, object[i].amount, object[i].pricePerUnit);
        i++;
    }

    return 0;
}
