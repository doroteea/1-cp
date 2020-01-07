#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int RetValue(int ,int *,int );
int main()
{
    int degree,value,i,x0;
    printf("The degree of the polynomial is: ");
    scanf("%d",&degree);
    int *pol=(int *)malloc(sizeof(int)*degree);
    for(i=0;i<=degree;i++)
    {
        printf("X^%d: ",i);
        scanf("%d",&pol[i]);
    }
    printf("The value of x0 is: ");
    scanf("%d",&x0);
    value=RetValue(degree,pol,x0);
    printf("Value of the derivative is: %d",value);
    return 0;
}

int RetValue(int degree,int *pol,int x0)
{
    int value,i;
    if(degree==0)
    {
        return 0;
    }
    if(degree==1)
    {
        value=pol[1]*x0;
        return value;
    }
    i=degree;
    value=0;
    int k=1;
    while(i>=1)
    {
        value = value+pol[i]*i*pow(x0,degree-k);
        i--;
        k++;
    }
    /*for(i=2;i<=degree;i++)
    {
        power=0;
        power=pow(x0,i-1);
        value += i*pol[i]*power;
    }
    */
    return value;

}
