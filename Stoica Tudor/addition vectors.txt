#include <stdlib.h>
#include "functii_elementare.h"

char s1[1005],s2[1005];
int v1[1005],size1;
int v2[1005],size2;
int maxx,dif,carry;
int rez[1005],size;
bool chooseOperation;

int main()
{
    coutMessage("Choose you operation (0-Addition/1-Multiplication)");
    cinInt(&chooseOperation);

    if(chooseOperation==0) /// addition
    {
        size1=cinInt();
        cinNextCharVec(s1,size1);

        size2=cinInt();
        cinNextCharVec(s2,size2);

        maxx=max(size1,size2);
        dif=maxx-min(size1,size2);

        for(int i=1; i<=maxx; i++)
        {
            if(i<=size1)
            {
                v1[i]=s1[i]-48;
            }

            if(i<=size2)
            {
                v2[i]=s2[i]-48;
            }
        }

        /********************************************//**
        * the next if else clauses make like:
        * from v1: 12345 -> size1=5 and v2: 41 -> size2=2
        * to v1: 12345 -> size1=5 and v2: 00041 -> size2=2 !!!
        ***********************************************/

        if(size1>size2)
        {
            for(int i=size2; i>=1; i--)
            {
                v2[i+dif]=v2[i];
                v2[i]=0;
            }
        }

        else
        {
            for(int i=size1; i>=1; i--)
            {
                v1[i+dif]=v1[i];
                v1[i]=0;
            }
        }

        for(int i=maxx; i>=0; i--)
        {
            int sum=v1[i]+v2[i]+carry;

            if(sum>=10)
            {
                carry=1;
                rez[++size]=sum%10;
            }

            else
            {
                carry=0;
                rez[++size]=sum;
            }
        }

        reverseIntVec(rez,size);
        coutIntVec(rez,size);
    }

    else /// multiplication
    {

    }

    return 0;
}
