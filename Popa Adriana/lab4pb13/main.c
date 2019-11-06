#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,v[100];
    int n,st,dr,mij,i,ok;
    printf("introduce n:");
    scanf("%d",&n);
    printf("introduce the numbers:");
    for(i=0; i<n; i++)
        scanf("%d",&v[i]);
    printf("introduce x:");
    scanf("%d",&x);
    st=0;dr=n-1;ok=0;
    while(st<dr&&ok==0)
    {
        mij=(st+dr)/2;
        if(v[mij]==x)
        {
            printf("x=%d and was found on position %d",x,mij);
            ok=1;
        }
        else if(v[mij]>x)
            dr=mij-1;
        else
            st=mij+1;
    }
    if(ok==0)
        printf("x does not exist in the sequence");
    return 0;
}
