#include <stdio.h>

int main()
{
    int n,i,d,nrDivizori=0;
    scanf("%d", &n);

    if (n==1)
    {
        printf("%d", 1);
    }
    if (n == 2) {
        printf("%d %d", 1, 2);
    }
    if (n==3)
    {
        printf("%d %d %d", 1,2,3);
    }
    if (n>3) {
        printf("%d %d %d ", 1,2,3);
            for (i = 4; i <= n; i++) {
                nrDivizori = 0;
                for (d = 2; d < i; d++) {
                    if (i % d == 0) {
                        nrDivizori++;
                    }
                }

                if (nrDivizori == 0) {
                    printf("%d ", i);
                }
            }
        }

    return 0;
}