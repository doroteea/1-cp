#include <stdio.h>
#include <stdlib.h>
void computePolynomials(int power1,int power2,int powert,int *pol1,int *pol2,int *computepol)
{
    int i,j;
    for(i=0;i<=powert;i++)
    {
        computepol[i]=0;
    }
    for(i=0;i<=power1;i++)
    {
        for(j=0;j<=power2;j++)
        {
            computepol[i+j]=computepol[i+j]+pol1[i]*pol2[j];
        }
    }
}
int main()
{
    int power1,power2,powert,i,j;
    scanf("%d",&power1);
    scanf("%d",&power2);
    powert=power1+power2;
    int *pol1=(int*)malloc(sizeof(int)*power1);
    int *pol2=(int*)malloc(sizeof(int)*power2);

    int *computepol=(int*)malloc(sizeof(int)*(power1+power2));
    for(i=0;i<=power1;i++)
    {
        printf("x^%d: ",i);
        scanf("%d",&pol1[i]);
    }
    for(j=0;j<=power2;j++)
    {
        printf("x^%d: ",j);
        scanf("%d",&pol2[j]);
    }
    computePolynomials(power1,power2,powert,pol1,pol2,computepol);
    for(i=0;i<=powert;i++)
    {
        if(computepol[i]!=0)
        {
           printf("%dX^%d+",computepol[i],i);
        }
    }
    return 0;
}
