#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x=3;

    while (x<=n)
    {
        short nrIsPrime=1;
        for (int divis=2; pow(divis,2)<=x; divis++)
        {
            if (x%divis==0)
            {
                nrIsPrime=0;
                break;
            }
        }
        if (nrIsPrime)
        {
            printf("%d ", x);
        }
        x++;
    }


    return 0;
}
