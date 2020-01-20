#include <stdio.h>
#include <stdlib.h>

void readSequence(float a[100],int n)
{

    for(int i=0;i<n;i++)
    {
        printf("Please insert the element:\n");
        scanf("%f",&a[i]);
    }
}

void printSequence(float a[100],int n)
{
    printf("The sequence is: ");
    for(int i=0;i<n;i++)
    {
        printf("%f ",a[i]);
    }
}

void minimumElement(float a[100],int n)
{
    float min=32000;
    int pos;
    for(int i=0;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            pos=i;
        }
    }
    printf("\nThe minimum of the sequence is %f on position %d",min,pos);
}

void maximumElement(float a[100],int n)
{
    float max=-32000;
    int pos;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            pos=i;
        }
    }
    printf("\nThe maximum of the sequence is %f on position %d",max,pos);
}
int main()
{
    float a[100];
    int n;
    printf("Please insert the number of elements:\nn=");
    scanf("%d",&n);
    readSequence(a,n);
    printSequence(a,n);
    minimumElement(a,n);
    maximumElement(a,n);
}
