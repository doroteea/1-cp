#include <stdio.h>
#include <stdlib.h>
void readp(int grad1,int *p)
{
    int i;
    for(i=0; i<=grad1; i++)
    {
        printf("x^%d:",i);
        scanf("%d",&p[i]);
    }
}
void readq(int grad2,int *q)
{
    int j;
    for(j=0; j<=grad2; j++)
    {
        printf("x^%d:",j);
        scanf("%d",&q[j]);
    }
}
void computePolynomials(int grad1,int grad2,int gradpro,int *p,int *q,int *productpoly)
{
    int i,j;
    for(i=0; i<=gradpro; i++)
    {
        productpoly[i]=0;
    }
    for(i=0; i<=grad1; i++)
    {
        for(j=0; j<=grad2; j++)
        {
            productpoly[i+j]=productpoly[i+j]+p[i]*q[j];
        }
    }
}

int main()
{
    int grad1,grad2,gradpro,i,j;
    scanf("%d",&grad1);
    scanf("%d",&grad2);
    gradpro=grad1+grad2;
    int *p=(int*)malloc(sizeof(int)*grad1);
    int *q=(int*)malloc(sizeof(int)*grad2);
    int *productpoly=(int*)malloc(sizeof(int)*gradpro);
    readp(grad1,p);
    readq(grad2,q);
    computePolynomials(grad1,grad2,gradpro,p,q,productpoly);
    for(i=0; i<=gradpro; i++)
    {
        if(productpoly[i]!=0)
        {
            printf("%dx^%d+",productpoly[i],i);
        }
    }
    return 0;
}

