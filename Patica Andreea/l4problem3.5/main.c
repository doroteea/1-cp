#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int squareRoot=1, squareNr=1;

    short nrIsSquare=0;

    while (pow(squareRoot, 2)<=n)
    {
        squareNr=pow(squareRoot, 2);
        squareRoot++;
    }
     printf("The greatest perfect square that is less than or equal to n is: %d\n", squareNr);


    int prime=n;
    short nrIsPrime=1;
    do
    {
        nrIsPrime=1;
        int divis=2;
        while (pow(divis, 2)<=prime)
        {
            if (prime%divis==0)
            {
                nrIsPrime=0;
                break;
            }
            divis++;
        }
        if (!nrIsPrime) prime++;
    }while (!nrIsPrime);

    printf("The least prime number that is greater than or equal to n is: %d", prime);

    return 0;
}
