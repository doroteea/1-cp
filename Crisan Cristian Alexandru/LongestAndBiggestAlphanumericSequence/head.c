#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compareArrayLenght(char *ArrayOne,char *ArrayTwo)
{
    if(strlen(ArrayOne)>strlen(ArrayTwo))
    {
        return 1;
    }
    else if(strlen(ArrayOne)<strlen(ArrayTwo))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int AlphanumericSizeOfAnArray(char *Array)
{
    int size=0;
    for(int i=0; i<strlen(Array); i++)
    {
        size=size+(int)Array[i];
    }
    return size;
}
int compareAlphanumericSize(char *ArrayOne,char *ArrayTwo)
{
    int AsizeOfArrayOne,AsizeOfArrayTwo;
    AsizeOfArrayOne=AlphanumericSizeOfAnArray(ArrayOne);
    AsizeOfArrayTwo=AlphanumericSizeOfAnArray(ArrayTwo);
    if(AsizeOfArrayOne>AsizeOfArrayTwo)
    {
        return 1;
    }
    else
    {
        if(AsizeOfArrayOne<AsizeOfArrayTwo)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }

}
/*void interchangeArrays(char *ArrayOne,char *ArrayTwo)
{
    char *aux;
    strcpy(aux,ArrayOne);
    strcpy(ArrayOne,ArrayTwo);
    strcpy(ArrayTwo,ArrayOne);
}*/
void longestAndBiggestSequence()
{
    int n,i=2;
    char longestArray[100],currentArray[100],biggestArray[100];
    printf("Give n:");
    scanf("%d",&n);
    printf("Give the arrays:\n");
    scanf("%s",&longestArray);
    strcpy(biggestArray,longestArray);
    while(i<=n)
    {
        scanf("%s",&currentArray);

        if(compareArrayLenght(longestArray,currentArray)==-1)
        {
            strcpy(longestArray,currentArray);
        }
        if(compareAlphanumericSize(biggestArray,currentArray)==-1)
        {
            strcpy(biggestArray,currentArray);
        }
     i++;
    }
printf("The longest sequence among the entered ones is: %s\n",longestArray);
printf("The biggest alphanumeric sequence among the entered ones is: %s\n",biggestArray);

}
