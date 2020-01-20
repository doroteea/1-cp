#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,seqlength,maxlength,startpos,endpos;;
    scanf("%d",&n);
    int *seq=(int*)malloc(sizeof(int)*n);
    seqlength=maxlength=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&seq[i]);
    }
    for(i=0;i<n-1;i++)
    {
        if(seq[i]<=seq[i+1])
        {
            seqlength++;
            if(seqlength>=maxlength)
            {
                maxlength=seqlength;
                startpos=i-seqlength;
                endpos=startpos+maxlength+1;
            }
        }
        else seqlength=0;
    }
    startpos=endpos-maxlength;
    for(i=startpos;i<=endpos;i++)
    {
        printf("%d ",seq[i]);
    }
    return 0;
}
