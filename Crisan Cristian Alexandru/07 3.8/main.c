#include <stdio.h>
#include <stdlib.h>
/*3.8. Write a function to compute the product of two polynomials,
 using only pointers and pointer expressions. */
void PolynomRead(int *Polynom,int PolGr)
{
    for(int i=PolGr;i>=0;i--)
    { printf(" The coefficient of x^%d is:",i);
    scanf("%d",&Polynom[i]);
    }
}
void PolynomWrite(int *Polynom,int PolGr)
{
    printf("P(X):");
    for(int i=PolGr;i>=0;i--)
    {
        if(Polynom[i]>0)
            {

        if(i<PolGr)
    {
        printf("+");
    }
        printf("%dx^%d",Polynom[i],i);

    }
    }
}
void ProductPolynomInitialize(int *PrPol,int PrPolGr)
{
    for(int i=0; i<=PrPolGr; i++)
        PrPol[i]=0;
}
void PolynomialProduct(int *Pol1,int *Pol2,int * PrPol, int Pol1Gr,int Pol2Gr,int PrPolGr)
{
ProductPolynomInitialize(PrPol,PrPolGr);

    for(int i=0; i<=Pol1Gr; i++)
    {
        for(int j=0; j<=Pol2Gr; j++)
        {
            PrPol[i+j]=PrPol[i+j]+Pol1[i]*Pol2[j];
        }
    }


}
int main()
{
    int *FirstPolynomial,*SecondPolynomial,*ProductPolynomial,Pol1Grade,Pol2Grade,PolPrGrade;
    printf("Give the first polynom's grade:");
    scanf("%d",&Pol1Grade);
    printf("Give the second polynom's grade:");
    scanf("%d",&Pol2Grade);
    PolPrGrade=Pol1Grade+Pol2Grade;
    FirstPolynomial=(int*)malloc(sizeof(int)*(Pol1Grade+1));
    SecondPolynomial=(int*)malloc(sizeof(int)*(Pol2Grade+1));
    ProductPolynomial=(int*)malloc(sizeof(int)*(PolPrGrade+1));
    PolynomRead(FirstPolynomial,Pol1Grade);
    PolynomRead(SecondPolynomial,Pol2Grade);
    PolynomialProduct(FirstPolynomial,SecondPolynomial,ProductPolynomial,Pol1Grade,Pol2Grade,PolPrGrade);
PolynomWrite(ProductPolynomial,PolPrGrade);


    return 0;
}
