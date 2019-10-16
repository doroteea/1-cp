#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
bool Prim(int numar){
    int div=0,i;
    for(i=2;i<=sqrt(numar);i++)
        if(numar%i==0)div++;
    if(div==0)return true;
    if(div!=0)return false;
}
int main()
{
    int nr;
    scanf("%d",&nr);
    for(int i=1;i<=nr;i++){
        if(Prim(i)==1){printf("%d\n",i);}
    }
    return 0;
}
