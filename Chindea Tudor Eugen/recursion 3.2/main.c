#include <stdio.h>
#include <stdlib.h>
int hermitPol(int x, int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return 2*x;
    }
    else
    {
        return(2*n*hermitPol(x,n-1)-2*(n-1)*hermitPol(x,n-2));
    }
}
int main()
{
    int x,n;
    printf("Type the value for x= ");
    scanf("%d",&x);
    printf("\ntype the value for n= ");
    scanf("%d",&n);
    int val=hermitPol(x,n);
    printf("\n the value of the polynamial is =%d",val);
    return 0;
}
