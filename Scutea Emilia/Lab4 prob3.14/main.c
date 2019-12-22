#include <stdio.h>
#include <stdlib.h>
int lengthmax=0;
int pos=0;
void readSequence(int *a,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Please insert the element a[%d]:",i);
        scanf("%d",&a[i]);
    }
}

void extractSequence(int *a,int n)
{
   int length=0;
   int i=0;
    while(a[i]<a[i+1] &&i<n)
    {
        length++;
        if(length>lengthmax)
        {
            lengthmax=length;
        }
        else
        {
            length=1;
            pos=i;
        }
    }
}

void printSequence(int *a,int n)
{
    printf("The maximum length subsequence which is in ascending order is: ");
    for(int i=pos;i<pos+lengthmax;i++)
    {
        printf("%d  ",a[i]);
    }
}

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
