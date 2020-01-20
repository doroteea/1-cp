/**3.2. Create a file containing a list of items a shop sells. An item is represented as a structure which contains:
    - a code;
    - a name;
    - a unit of measure;
    - the amount;
    - price per unit

3.3 sort those in ascending order based on code*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int code;
    char *name;
    char *unit;
    float amount;
    float price;
} itemType;

void readItems(FILE *firstFile, int nrItems)
{
    int i;
    itemType *items = (itemType*)malloc(sizeof(itemType)*20);

    for(i=0; i<nrItems; i++)
    {
        items[i].name = malloc(sizeof(char)*10);
        items[i].unit = malloc(sizeof(char)*10);

        getchar();
        printf("Item #%d\n",i+1);
        printf("\tName: ");
        scanf("%s",items[i].name);
        getchar();
        printf("\tUnit: ");
        scanf("%s",items[i].unit);
        printf("\tCode: ");
        scanf("%d",&items[i].code);
        printf("\tAmount: ");
        scanf("%f",&items[i].amount);
        printf("\tPrice: ");
        scanf("%f",&items[i].price);

        fprintf(firstFile,"\n%s %s %d %f %f",items[i].name,items[i].unit,items[i].code,items[i].amount,items[i].price);

    }
}

void readData(FILE *firstFile)
{
    int nrItems;
    printf("Input the number of items: ");
    scanf("%d",&nrItems);

    fprintf(firstFile,"%d",nrItems);

    readItems(firstFile,nrItems);
}

int charToInt(char *string)
{
    int length = strlen(string);
    int i,number = 0, digit;

    for(i=0; i<length; i++)
    {
        digit = string[i] - '0';
        number = number*10 + digit;
    }

    return number;
}

void sortItems(FILE *firstFile, FILE *sortFile)
{
    int nrItems, i;
    fscanf(firstFile,"%d",&nrItems);

    itemType *items = (itemType*)malloc(sizeof(itemType)*nrItems);

    char * strbuf = (char*) malloc(sizeof(char)*51);

    fgets(strbuf, 50, firstFile);

    int currentItem = 0;
    while(fgets(strbuf, 50, firstFile) != NULL)
    {
        char *p;
        i=1;
        for(p = strtok(strbuf," "); p ; p = strtok(NULL," "))
        {

            if(i==3)
            {
                items[currentItem].code = charToInt(p);
            }
            if(i==4)
            {
                items[currentItem].amount = charToInt(p);
            }
            if(i==5)
            {
                items[currentItem].price = charToInt(p);
            }

            i++;
        }
        currentItem++;
    }

    int j;
    for(i=0; i<nrItems-1; i++)
    {
        for(j=i; j<nrItems; j++)
        {
            if(items[i].code > items[j].code)
            {
                int aux;
                aux = items[i].code;
                items[i].code = items[j].code;
                items[j].code = aux;
            }
        }
    }

    for(i=0; i<nrItems; i++)
    {
        fprintf(sortFile,"%d\n",items[i].code);
    }

}

int main()
{
    FILE *firstFile;
    firstFile = fopen("initial.txt","r+");

    readData(firstFile);

    FILE *sortFile;
    sortFile = fopen("sort.txt","w");

    ///big brain time

    fclose(firstFile);

    firstFile = fopen("initial.txt","r");

    ///end of big brain time

    sortItems(firstFile,sortFile);

    return 0;
}
