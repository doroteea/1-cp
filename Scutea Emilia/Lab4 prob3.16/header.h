#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void readSequence(int *a,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Please insert the element:");
        scanf("%d",&a[i]);
    }

}

void printSequence(int *a,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");
}
void ascendingOrder(int *a,int n)
{
    int ok=0;
    while(ok==0)
    {
        ok=1;
        for(int i=0; i<n-1; i++)
            if(a[i]>a[i+1])
            {
                int aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
                ok=0;
            }
    }

}

void computeSequenceElementsFromBothStrings(int *a,int *b,int *c, int n,int m)
{
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        while(a[i]<b[j] &&i<n)
        {
            i++;
        }
        while(b[j]<a[i] && j<n)
        {
            j++;
        }
        if(a[i]==b[j])
        {
            c[k++]=a[i];
            i++;
            j++;
        }
    }
    printf("The string that contains all the elements belonging to both strings is:\n");
    printSequence(c,k);
}

void computeSequenceAllElementsWrittenOnce(int *a,int *b,int *d,int n,int m)
{
    int i=0,j=0,k=0;
    while(i<n && j<n)
    {
        if(a[i]==b[j])
        {
            d[k]=a[i];
            k++;
            i++;
            j++;
        }
        else
        {
            if(a[i]<b[j])
            {
                d[k]=a[i];
                k++;
                i++;

            }
            else
            {
                d[k]=b[j];
                k++;
                j++;
            }
        }
    }
    while(i<n)
    {
        d[k++]=a[i];
        i++;
    }
    while(j<m)
    {
        d[k++]=b[j];
        j++;
    }
    printf("The string of all the elements of the two given strings, written once is:\n ");
    printSequence(d,k);
}


void computeSequenceElementsFirstStringOnly(int *a,int *b,int *e,int n,int m)
{
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            i++;j++;
        }
        else
        {
            if(a[i]<b[j])
            {
                e[k]=a[i];
                i++;k++;
            }
        }
    }
    while(i<n)
    {
        e[k]=a[i];
        i++;k++;
    }
    printf("The string of the elements from the first string, without the elements that are also in the second string is:\n");
    printSequence(e,k);
}
