
#include "header.h"

int main()
{
    int n;
    printf("Please insert the length of the first sequence:\nn=");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int*)*n);
    readSequence(a,n);
    ascendingOrder(a,n);
    printSequence(a,n);

    int m;
    printf("\nPlease insert the length of the second sequence:\nm=");
    scanf("%d",&m);
    int *b=(int*)malloc(sizeof(int*)*m);
    readSequence(b,m);
    ascendingOrder(b,m);
    printSequence(b,m);


    int *c=(int*)malloc(sizeof(int*)*n);
    computeSequenceElementsFromBothStrings(a,b,c,n,m);
    int *d=(int*)malloc(sizeof(int)*(2*n));
    computeSequenceAllElementsWrittenOnce(a,b,d,n,m);
    int *e=(int*)malloc(sizeof(int*)*n);
    computeSequenceElementsFirstStringOnly(a,b,e,n,m);


}
