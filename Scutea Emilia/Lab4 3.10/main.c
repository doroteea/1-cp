#include <stdio.h>
#include <stdlib.h>
int a;
int *nr;
void nr_bancnote (int *nr, int a)
{
    *nr=0;
    if(a>=500)
    {
        while(a>=500)
        {
            a=a-500;
            *nr=*nr+1;
        }

    }
    if(a>=200)
    {
        while(a>=200)
        {
            a=a-200;
            *nr=*nr+1;
        }
    }
    if(a>=100)
    {
        while(a>=100)
        {
            a=a-100;
            *nr=*nr+1;
        }
    }
    if(a>=50)
    {
        while(a>=50)
        {
            a=a-50;
            *nr=*nr+1;
        }
    }
    if(a>=10)
    {
        while(a>=10)
        {
            a=a-10;
            *nr=*nr+1;
        }
    }
    if(a>=5)
    {
        while(a>=5)
        {
            a=a-5;
            *nr=*nr+1;
        }
    }
    if(a>=1)
    {
        while(a>=1)
        {
            a=a-1;
            *nr=*nr+1;
        }
    }


}
int main()
{
    printf("Introduce the amount of money:\n");
    scanf("%d",&a);
    int *nr=(int*)malloc(sizeof(int));
    nr_bancnote(nr,a);
    printf("There are %d banknotes needed to pay the amount",*nr);
    return 0;
}
