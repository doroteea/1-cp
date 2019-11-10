#include <stdio.h>
#include <stdlib.h>

int main()
{ int i,j,n,max=0;
printf("Enter n:\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    j=0;
    while(i>j)
    {
        j++;
        if(i==j*j)
        {
            if(i>max)
            {
                max=i;
            }
        }
    }
}
printf("%d",max);

    return 0;
}
