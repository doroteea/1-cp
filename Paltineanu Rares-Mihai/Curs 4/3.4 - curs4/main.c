#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, g = 0;
    scanf("%d", &n);
    if(n >= 2)
    {
        printf("2\n");
        for(int i = 3; i <= n; i+=2)
        {
            for(int j = 2; j <= i/2 && !g; j++)
                if(i%j == 0)
                    g = 1;
            if(!g)
                printf("%d\n", i);
            g = 0;
        }
    }
    return 0;
}
