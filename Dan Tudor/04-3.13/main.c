#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s[100],i,n,x,pos=-1;
    scanf("%d%d",&n,&x);
    for(i=0; i<n; i++)
    {
        scanf("%d",&s[i]);
    }
    for(i=0; i<n; i++)
    {
        if(s[i] == x)
            pos = i;
    }
    if(pos != -1)
    {
        printf("DA %d",pos);
    }
    else
    {
        printf("NU");
    }
    return 0;
}
