#include <stdio.h>
#include <stdlib.h>

int recursive(int n,int x)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        if(n==1)
            return 2*x;
        else
        {
            return (2*n*recursive(n-1,x)-2*(n-1)*recursive(n-2,x));
        }
    }
}
int main()
{
    int n,x;
    printf("Please input the power of the polynomial:\nn=");
    scanf("%d",&n);
    printf("Please input x:\nx=");
    scanf("%d",&x);
    int f=recursive(n,x);
    printf("The result is %d",f);
    return 0;
}
