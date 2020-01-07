///3.7.Using the enum type,add the Boolean type.
///    Then write a function to sort a string in ascending order using bubble sort. And a Boolean semaphore.

#include <stdio.h>
#include <stdlib.h>

typedef enum {false,true}booleanEnum;

int *readString(int nrElements)
{
    int i;
    int *numbers = (int*)malloc(sizeof(int)*nrElements);
    for(i=0; i<nrElements; i++)
        scanf("%d",&numbers[i]);

    return numbers;
}

int *bubbleSort(int *numbers, int nrElements)
{
    booleanEnum isSorted;

    int i,j;
    ///this is just a copy paste of bubbleSort honestly
    for(i=0; i<nrElements - 1; i++)
    {
        isSorted = false;
        for(j=0; j<nrElements - i - 1; j++)
        {
            if(numbers[j] > numbers[j+1])
            {
                int aux;
                aux = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = aux;
                isSorted = true;
            }
        }
        if(isSorted == false)break;
    }

    return numbers;

}

void printString(int *numbers, int nrElements)
{
    int i;
    for(i=0; i<nrElements; i++)
        printf("%d ",numbers[i]);
}

int main()
{
    int nrElements;
    printf("Input number of elements of string: ");
    scanf("%d",&nrElements);
    int *numbers = (int*)malloc(sizeof(int)*nrElements);

    numbers = readString(nrElements);

    numbers = bubbleSort(numbers,nrElements);

    printString(numbers,nrElements);

    return 0;
}
