#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numerator,denominator;
} rational;

rational readFraction()
{
    rational x;
    printf("give the numerator:");
    scanf("%d",&x.numerator);
    printf("give the denominator:");
    scanf("%d",&x.denominator);
    return x;
}

void printFarction(rational x)
{
    printf("your fraction is: %d/%d\n",x.numerator,x.denominator);
}

rational simplification(rational x)
{
    int i,min;
    if(x.numerator>x.denominator)
        min=x.denominator;
    else
        min=x.numerator;
    for(i=min; i>=2; i--)
    {
        if(x.denominator%i==0&&x.numerator%i==0)
        {
            x.denominator=x.denominator/i;
            x.numerator=x.numerator/i;
        }
    }
    return x;
}

rational addition(rational x,rational y)
{
    rational z;
    z.numerator=x.numerator*y.denominator+x.denominator*y.numerator;
    z.denominator=x.denominator*y.denominator;
    z=simplification(z);
    return z;
}

rational subtraction(rational x,rational y)
{
    rational z;
    z.numerator=x.numerator*y.denominator-x.denominator*y.numerator;
    z.denominator=x.denominator*y.denominator;
    z=simplification(z);
    return z;
}

rational divide(rational x,rational y)
{
    rational z;
    z.numerator=x.numerator*y.denominator;
    z.denominator=x.denominator*y.numerator;
    z=simplification(z);
    return z;
}

rational power(rational x,int n)
{
    rational z=x;
    int i;
    for(i=2; i<=n; i++)
    {
        z.numerator=z.numerator*x.numerator;
        z.denominator=z.denominator*x.denominator;
        z=simplification(z);
    }
    return z;
}

int main()
{
    printf("give the fraction you want to simplify:\n");
    rational x=readFraction();
    printFarction(x);
    x=simplification(x);
    printFarction(x);

    printf("give the fractions you want to add:\n");
    x=readFraction();
    rational y=readFraction();
    x=addition(x,y);
    printFarction(x);

    printf("give the fractions you want to subtrack:\n");
    x=readFraction();
    y=readFraction();
    x=subtraction(x,y);
    printFarction(x);

    printf("give the fractions you want to divide:\n");
    x=readFraction();
    y=readFraction();
    x=divide(x,y);
    printFarction(x);

    printf("give the fraction:\n");
    x=readFraction();
    int n;
    printf("introduce the power:\n n=");
    scanf("%d",&n);
    x=power(x,n);
    printFarction(x);
    return 0;
}
