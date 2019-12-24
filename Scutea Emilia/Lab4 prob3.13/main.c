#include "header.h"

int main()
{
    int n;
    printf("Please input the length of the sequence:\nn=");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    readSequence(a,n);
    int x;
    printf("Please insert the number you want to verify:\nx=");
    scanf("%d",&x);
    verifyExistence(x,a,n);
}
