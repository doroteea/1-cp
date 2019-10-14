///i hope that i did what you sugessted. Thanks!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{

    clock_t x, y;
    float time;
    int a;
    x = clock();
    while(scanf("%d",&a))
    {
            y = clock();
            time = (float)(y - x)/CLOCKS_PER_SEC;
            printf("%f", time);
    }

    return 0;
}
