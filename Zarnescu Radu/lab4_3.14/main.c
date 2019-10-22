#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int n,a,b,seq[100],seqmax[100],length,maxlength,i=2,j;
    scanf("%d",&n);
    scanf("%d",&a);
    seq[1]=a;
    length=1;
    maxlength=1;
    while(i<=n)
    {
        scanf("%d",&b);
        if(a<b)
        {
            length++;
            seq[length]=b;
        }
        else
        {
            if(length>maxlength)
            {
                maxlength=length;
                for(j=1; j<=maxlength;j++)
                {
                    seqmax[j]=seq[j];
                }
            }
            length=1;
            seq[1]=b;
        }
        a=b;
        i++;
    }
    if(length>maxlength)
    {
        maxlength=length;
        for(i=1; i<=maxlength;i++)
        {
            seqmax[i]=seq[i];
        }
    }
    printf("maximum sequence is:");
    for(i=1; i<=maxlength; i++)
    {
        printf("%d ",seqmax[i]);
    }
    return 0;
}
