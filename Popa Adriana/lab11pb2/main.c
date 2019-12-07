#include "list.h"

int main()
{
    items *a=readList();
    printf("\nYour list is:\n");
    printList(a);

    printf("\nThe list sorted is:\n");
    items *b=sort(a);
    printList(b);

    int nrOfItems,i;
    printf("introduce the number of items you want to add: ");
    scanf("%d",&nrOfItems);
    int *poz=(int*)(malloc(sizeof(int*)*MAX_LENGTH));
    for(i=0; i<nrOfItems; i++)
    {
        printf("Give the position on which you want to introduce the item %d:",i+1);
        scanf("%d",&poz[i]);
    }
    items *c=readItems(nrOfItems);
    a=introduceItems(poz,c,a,nrOfItems);
    printList(a);

    printf("introduce the number of items you want to delete: ");
    scanf("%d",&nrOfItems);
    a=deleteItems(a,nrOfItems);
    printList(a);
    return 0;
}
