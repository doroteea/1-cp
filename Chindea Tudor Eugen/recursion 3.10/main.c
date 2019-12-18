#include <stdio.h>
#include <stdlib.h>
int Ackerman(int m, int n)
{
    if(m==0)
    {
        return n+1;
    }
    else if(n==0)
    {
        return Ackerman(m-1,1);
    }
    else
    {
        return Ackerman(m-1,Ackerman(m,n-1));
    }
}
int main()
{
    int x=Ackerman(1,2);
    printf("x= %d",x);
    return 0;
}
