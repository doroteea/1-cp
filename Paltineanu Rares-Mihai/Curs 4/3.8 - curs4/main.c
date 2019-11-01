/**Read from the standard input the degree and the coefficients of the polynomial p(x)=a0+a1x1+...+ anxn.
Compute and display the value of the polynomial for x= x0(x0is read from the standard input).
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int pol[200], n, x;
    double sumPol = 0;
    for(int i = 0; i < 200; i++)
    {
        pol[i] = 0;
    }

    printf("Read the degree of the polynomial pol: ");
    scanf("%d", &n);
    printf("Read the value of x: ");
    scanf("%d", &x);
    for(int i = 0; i <= n; i++)
    {
        scanf("%d", &pol[i]);
        sumPol = sumPol + pol[i]*pow(x,i);
    }

    printf("The value of the polynomial:");
    for(int i = 0; i <= n; i++)
    {
        if(i == 0 && pol[i] != 0)
        {
            printf("%d ", pol[i], i);
        }
        else if(i == 1 && pol[i] != 0)
        {
            if(pol[i] == 1)
            {
                printf("+ x ", i);
            }
            else
            {
                printf("+ %dx ", pol[i], i);
            }
        }
        else if(pol[i] != 0 && i < n - 1)
        {
            if(pol[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else
            {
                printf("+ %dx^%d ", pol[i], i);
            }
        }
        else if(pol[i] != 0 && i == n - 1)
        {
            if(pol[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else
            {
                printf("%dx^%d ", pol[i], i);
            }

        }
        else if(i == n && pol[i] != 0)
        {
            if(pol[i] == 1)
            {
                printf("+ x^%d", i);
            }
            else
            {
                printf("+ %dx^%d", pol[i], i);
            }

        }
    }

    printf("\tin the point %d is: ", x);

    printf("%lf", sumPol);
    return 0;
}
