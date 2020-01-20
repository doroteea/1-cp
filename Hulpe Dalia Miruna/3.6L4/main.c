#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,mirrored=0,copy;
    scanf("%d",&n);
    copy=n;
    while(copy!=0)
    {
        mirrored=mirrored*10+copy%10;
        copy=copy/10;
    }
    if(n==mirrored)
        printf("Yes");
    else
        printf("No");
    return 0;

}
