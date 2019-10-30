#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int  i = 0; i < 24; i ++)
    {

        if(i < 10)
        {
            printf("0%d:00:00\n", i); ///nu inteleg de ce imi oune un singur 0
        }
        else
            printf("%d:00:00\n", i);

        for(int j = 0; j < 60; j++)
        {

            if(j != 0)
            {
                if(j < 10)
                    printf("%d:0%d:00\n", i, j);
                else
                    printf("%d:%d:00\n", i, j);
            }

            for(int k = 0; k < 60; k++)
            {
                if(j != 0 && k != 0)
                {
                    if(k<10)
                        printf("%d:%d:0%d\n", i, j,k);
                    else
                        printf("%d:%d:%d\n", i, j,k);
                }

            }
        }
    }
    return 0;
}
