#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int *b, int *sorted)
{
    int i,j,k;
    i=0; j=0; k=0;
    int n= sizeof(a) / sizeof(a[0]);
    int m= sizeof(b) / sizeof(b[0]);

    while(i < n && j < m)
    {
        if(a[i] < b[j])
        {
            sorted[k] = a[i];
            k++;
            i++;
        }
        else
        {
            sorted[k] = b[j];
            k++;
            j++;
        }
    }

}

int main()
{
    int lengthFirstArray,lengthSecondArray,lengthThirdArray;
    printf("Length of the first array: ");
    scanf("%d", &lengthFirstArray);

    int *a=(int*)malloc(sizeof(int) * lengthFirstArray);
    for (int i=0; i < lengthFirstArray; i++)
    {
        printf("a[%d]= ",i);
        scanf("%d",&a[i]);
    }

    printf("Length of the second array: ");
    scanf("%d", &lengthSecondArray);

    int *b=(int*)malloc(sizeof(int) * lengthSecondArray);
    for (int i=0; i < lengthSecondArray; i++)
    {
        printf("b[%d]= ",i);
        scanf("%d",&b[i]);
    }

    lengthThirdArray=lengthFirstArray+lengthSecondArray;
    int *sorted=(int*)malloc(sizeof(int) * lengthThirdArray);

    merge(a,b,sorted);

    for (int i=0;i<lengthThirdArray;i++)
    {
        printf("%d ", sorted[i]);
    }

    return 0;
}