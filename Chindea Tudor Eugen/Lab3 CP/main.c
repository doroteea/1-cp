#include <stdio.h>
#include <stdlib.h>

int main()
{
    // continue - este folosit in for  si cand se apeleaza se intoarce la inceput de for si creste contorul
    // continue e poate folosi in orice functie repetitiva; te aduce la inceputul instructiunilor
    int sequence[100],n,mini,pozmin[100],maxi,pozmax[100],ctmin=1,ctmax=1,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&sequence[i]);
        if(i==0)
        {
            mini=sequence[i];
            maxi=sequence[i];
            pozmin[0]=i;
            pozmax[0]=i;
        }
        else
        {
            if(sequence[i]>maxi)
            {
                maxi=sequence[i];
                ctmax=0;
                pozmax[ctmax]=i;
            }
            else if(sequence[i]==maxi)
            {
                ctmax++;
                pozmax[ctmax]=i;
            }
            if(sequence[i]<mini)
            {
                mini=sequence[i];
                ctmin=0;
                pozmin[0]=i;
            }
            else if(sequence[i]==mini)
            {
                ctmin++;
                pozmin[ctmin]=i;
            }
        }

    }
    printf("Valoarea maxima este=%d  si apare pe pozitile\n",maxi);
    for(i=0; i<=ctmax; i++)
        printf("%d ",pozmax[i]);
    printf("Valoarea minima este=%d si apare pe pozitile\n",mini);
    for(i=0; i<=ctmin; i++)
        printf("%d ",pozmin[i]);
    return 0;
}
