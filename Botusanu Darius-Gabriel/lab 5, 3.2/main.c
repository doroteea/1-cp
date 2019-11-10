#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
/*dunno why it doesn't print the roots*/
int readPoly(int *n, int a[])
{
    int i;
    printf("\nPlease input the degree of your polynomial: ");
    scanf("%d", n);
    for(i=0;i<=*n;i++)
    {
        printf("\na[%d]=", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
    return 0;
}
int main()
{
    int i,n,j;
    int p[sizeof(n)];
    readPoly(&n, p);
    for(i=0;i<=n;i++)
    {
        for(j=1;j<=p[0];j++)
        {
            if(p[0]%j==0)
            {
                if(p[i]*j==0)
                {
                    printf("%d is a root!", j);
                }
            }
        }
    }
    return 0;
}
