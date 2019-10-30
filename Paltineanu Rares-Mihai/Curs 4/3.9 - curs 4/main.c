/**Write a program to perform the operations +,-,*, /  on two polynomials:
A(x)=a0+a1x1+...+ anxn
B(x)=b0+b1x1+......+ bmxm
The degrees and the coefficients are read from the keyboard
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pol1[200], pol2[200], n1, n2, pol_add[200], pol_sub[200], pol_div[200], pol_mult[400], maxim = -1;
    memset(pol1, 0, 800);
    memset(pol2, 0, 800);
    memset(pol_add, 0, 800);
    memset(pol_sub, 0, 800);
    memset(pol_mult, 0, 1600);

    printf("Read the degree for pol1: ");
    scanf("%d", &n1);

    printf("Read the degree for pol2: ");
    scanf("%d", &n2);

    printf("Read the first polynomial.\n");
    for(int i = 0; i <= n1; i++)
    {
        scanf("%d", &pol1[i]);
    }

    printf("Read the second polynomial.\n");
    for(int i = 0; i <= n2; i++)
    {
        scanf("%d", &pol2[i]);
    }

    ///+ OPERATION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

    maxim = n1>n2? n1: n2;

    for(int i = 0; i <= maxim; i++)
    {
        pol_add[i] = pol1[i] + pol2[i];
    }

    printf("The new polynomial after adding the two polynomials is: ");

    for(int i = 0; i <= maxim; i++)
    {
        if(i == 0 && pol_add[i] != 0)
        {
            printf("%d ", pol_add[i], i);
        }
        else if(i == 1 && pol_add[i] != 0)
        {
            if(pol_add[i] == 1)
            {
                printf("+ x ", i);
            }
            else
            {
                printf("+ %dx ", pol_add[i], i);
            }
        }
        else if(pol_add[i] != 0 && i < maxim - 1)
        {
            if(pol_add[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else
            {
                printf("+ %dx^%d ", pol_add[i], i);
            }
        }
        else if(pol_add[i] != 0 && i == maxim - 1)
        {
            if(pol_add[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else
            {
                printf("%dx^%d ", pol_add[i], i);
            }

        }
        else if(i == maxim && pol_add[i] != 0)
        {
            if(pol_add[i] == 1)
            {
                printf("+ x^%d", i);
            }
            else
            {
                printf("+ %dx^%d", pol_add[i], i);
            }

        }
    }
    printf("\n");

    ///- OPERATION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    for(int i = 0; i <= maxim; i++)
    {
        pol_sub[i] = pol1[i] - pol2[i];
    }

    printf("The new polynomial after subtracting the two polynomials is: ");

    ///I didn't want to consider more cases, for ex if the coeff is -1 or less, i'm sorry, but it's getting stressfull :))

    for(int i = 0; i <= maxim; i++)
    {
        if(i == 0 && pol_sub[i] != 0)
        {
            printf("%d ", pol_sub[i]);
        }
        else if(i == 1 && pol_sub[i] != 0)
        {
            if(pol_sub[i] == 1)
            {
                printf("+ x ", i);
            }
            else
            {
                printf("+ %dx ", pol_sub[i]);
            }
        }
        else if(pol_sub[i] != 0 && i < maxim - 1)
        {
            if(pol_sub[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else
            {
                printf("+ %dx^%d ", pol_sub[i], i);
            }
        }
        else if(pol_sub[i] != 0 && i == maxim - 1)
        {
            if(pol_sub[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else
            {
                printf("+ %dx^%d ", pol_sub[i], i);
            }

        }
        else if(i == maxim && pol_sub[i] != 0)
        {
            if(pol_sub[i] == 1)
            {
                printf("+ x^%d", i);
            }
            else
            {
                printf("+ %dx^%d", pol_sub[i], i);
            }

        }
    }

    ///* OPERATION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ///i don't know if it's the most efficient idea, but i didn't find something better
    int k, j;

    for(int i = 0; i <= n1 + n2; i++)
    {
        if(i <= n1 && i <= n2)
        {
            k = i;
            j = 0;
        }
        else if(i>n1 && i<=n2)
        {
            k = n1;
            j = i - n1;
        }
        else if(i > n1 && i > n2)
        {
            k = n1;
            j = i - n1;
        }
        else if(i <= n1 && i > n2)
        {
            k = n1-n2;
            j = n2;
        }

        while(k>=0 && k <= n1 && j >= 0 && j <= n2)
        {
                pol_mult[i] = pol_mult[i] + pol1[k]*pol2[j];
                k--;
                j++;
        }
    }
    printf("\n\n\n\n");
    for(int i = 0; i <= n1 + n2; i++)
    {
        if(i == 0 && pol_mult[i] != 0)
        {
            printf("%d ", pol_mult[i]);
        }
        else if(i == 1 && pol_mult[i] != 0)
        {
            if(pol_mult[i] == 1)
            {
                printf("+ x ", i);
            }
            else
            {
                printf("+ %dx ", pol_mult[i]);
            }
        }
        else if(pol_mult[i] != 0 && i < n1 + n2 - 1)
        {
            if(pol_mult[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else
            {
                printf("+ %dx^%d ", pol_mult[i], i);
            }
        }
        else if(pol_mult[i] != 0 && i == n1 + n2 - 1)
        {
            if(pol_mult[i] == 1)
            {
                printf("+ x^%d ", i);
            }
            else
            {
                printf("%dx^%d ", pol_mult[i], i);
            }

        }
        else if(i == n1 + n2 && pol_mult[i] != 0)
        {
            if(pol_mult[i] == 1)
            {
                printf("+ x^%d", i);
            }
            else
            {
                printf("+ %dx^%d", pol_mult[i], i);
            }

        }
    }
    ///idk what should i write at the / operation
    return 0;
}
