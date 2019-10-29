#include <stdio.h>
#include <stdlib.h>
void swap(int i, int j)// nu se salveaza swapul
{
    int aux=i;
    i=j;
    j=aux;
}
void swap2(int* i,int* j)
{
    int aux=*i;
    *i=*j;
    *j=aux;
}
int main()
{
   int a=8,b=9;
   swap2(&a,&b);
   printf("%d",b);
    return 0;
}
