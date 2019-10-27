#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* Sum (char *s1, char *s2, int n, int m)
{
    int i = n - 1, j = m - 1, k = n - 1, carry = 0, sum;
    char *s = (char*)malloc(sizeof(char) * (n + 2));
    while (j >= 0)
    {
        sum = s1[i] + s2[j] + carry - 2 * '0';
        s[k] = '0' + sum % 10;
        carry = sum / 10;
        i--; j--; k--;
    }
    while (i >= 0)
    {
        sum = s1[i] + carry - '0';
        s[k] = '0' + sum % 10;
        carry = sum / 10;
        i--; k--;
    }
    s[n] = '\0';
    if (carry > 0)
    {
        for (i = n; i >= 0; i--)
            s[i + 1] = s[i];
        s[0] = '1';
    }
    return s;
}

int main()
{
    int n1, n2;
    printf ("how many digits in first number? ");
    scanf ("%d", &n1);
    char *s1 = (char*)malloc(sizeof(char) * (n1 + 1));
    printf ("n1 = "); scanf ("%s", s1);
    printf ("how many digits in second number? ");
    scanf ("%d", &n2);
    char *s2 = (char*)malloc(sizeof(char) * (n2 + 1));
    printf ("n2 = "); scanf ("%s", s2);

    if (n1 > n2)
    {
        char *s = (char*)malloc(sizeof(char) * (n1 + 2));
        s = Sum (s1, s2, n1, n2);
        printf ("The sum is %s", s);
    }
    else
    {
        char *s = (char*)malloc(sizeof(char) * (n2 + 2));
        s = Sum (s2, s1, n2, n1);
        printf ("The sum is %s", s);
    }
    return 0;
}
