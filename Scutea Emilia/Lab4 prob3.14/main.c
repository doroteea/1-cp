#include "header.h"
int lengthmax=0;
int pos=0;
int main()
{
    int n;
    printf("Please input the length of the sequence:\nn=");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    readSequence(a,n);
    extractSequence(a,n);
    printSequence(a,n);
}
