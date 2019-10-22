#include <stdio.h>
#include <stdlib.h>

int main()
{unsigned n,i,d,OK;
scanf("%d",&n);
printf("The prime numbers are\n");
for(i=1;i<=n;i++)
{OK=1;
    for(d=2;d<=i/2;d++)
    {
        if(i%d==0)
        {
            OK=0;
            break;
        }

        if(OK=1)
        {
            printf("&d",i);
        }

    }

}

    return 0;
}
