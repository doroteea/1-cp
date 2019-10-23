#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, a[1001];
    printf("Insert the number n\n");
    scanf("%d", &n);
    printf("Insert the sequence\n");
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
    }

    int x;
    printf("Insert the number x\n");
    scanf("%d", &x);

    int f=1, l=n, mid;
    bool exists=false;

    while (f<=l)
    {
        if (f==l && x==a[f])
        {
            exists=true;
            printf("The number %d exists on position: %d", x, f);
            break;
        }
        mid=(f+l)/2;
        if (x<=a[mid])
        {
            l=mid;
        }
        else
        {
            f=mid+1;
        }
    }
    if (!exists)
    {
        printf("The number %d does not exist in the sequence.", x);
    }

    return 0;
}
