#include <stdio.h>
#include <stdlib.h>
int n;
int *nrbanc;
void numarMin_bancnote (int *nrbanc, int n)
{
    *nrbanc=0;
    if(n>=500)
    {
        while(n>=500)
        {
            n=n-500;
            *nrbanc=*nrbanc+1;
        }

    }
    if(n>=200)
    {
        while(n>=200)
        {
            n=n-200;
            *nrbanc=*nrbanc+1;
        }
    }
    if(n>=100)
    {
        while(n>=100)
        {
            n=n-100;
            *nrbanc=*nrbanc+1;
        }
    }
    if(n>=50)
    {
        while(n>=50)
        {
            n=n-50;
            *nrbanc=*nrbanc+1;
        }
    }
    if(n>=10)
    {
        while(n>=10)
        {
            n=n-10;
            *nrbanc=*nrbanc+1;
        }
    }
    if(n>=5)
    {
        while(n>=5)
        {
            n=n-5;
            *nrbanc=*nrbanc+1;
        }
    }
    if(n>=1)
    {
        while(n>=1)
        {
            n--;
            *nrbanc=*nrbanc+1;
        }
    }


}
int main()
{
    scanf("%d",&n);
    int *nrbanc=(int*)malloc(sizeof(int));
    numarMin_bancnote(nrbanc,n);
    printf("%d",*nrbanc);
    return 0;
}
