#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int n,i,seq[100],left,right,middle,x,found=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&seq[i]);
    }
    scanf("%d",&x);
    left=1;
    right=n;
    while(left<right)
    {
        middle=(left+right)/2;
        if(x==seq[middle])
        {
            printf("nr %d exists in sequence \n position:%d",x,middle);
            left=right+1;
            found=1;
        }
        else
            {
                if(x>seq[middle])
                {
                    left=middle+1;
                }
                else
                {
                    right=middle-1;
                }
            }
    }
    if(found==0)
        printf("nr %d doesnt exist in sequence",x);

    return 0;
}
