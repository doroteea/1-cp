#include <stdio.h>
#include <stdlib.h>
int nrprim(int x)
{
    int diviz=2;
    while(diviz*diviz<=x)
    {
        if(x%diviz==0)
            return 0;
        diviz++;
    }
    return 1;
}
int patratperf(int x)
{
    int i=1;
    while(i*i<x)
    {
        i++;
    }
    if(i*i==x)
        return 1;
    return 0;
}
int main()
{
    int n,sem=0,i;
    scanf("%d",&n);
    for( i=n; sem==0; i++)
    {
        if(nrprim(i))
            sem=i;
    }
    printf("Cel mai mic nr prim mai mare sau egal cu n= %d\n",sem);
    sem=0;
    for( i=n; sem==0; i--)
    {
        if(patratperf(i))
            sem=i;
    }
    printf("Cel mai mare patrat perf mai mic decat n= %d",sem);
    return 0;
}
