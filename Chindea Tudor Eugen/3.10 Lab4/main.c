#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RON,nrBancnote=0,i;
    int *tipBancnota=(int*)malloc(sizeof(int)*8);//avem 7 tipuri de bancnote
    tipBancnota[0]=1;
    tipBancnota[1]=5;
    tipBancnota[2]=10;
    tipBancnota[3]=50;
    tipBancnota[4]=100;
    tipBancnota[5]=200;
    tipBancnota[6]=500;

    scanf("%d",&RON);
    while(RON)
    {
        for(i=6;i>=0;i--)
        {
            while(RON>=tipBancnota[i])
            {
                RON=RON-tipBancnota[i];
                nrBancnote++;
            }
        }
    }
    printf(" Este nevoie de minim= %d  bancnote",nrBancnote);
    return 0;
}
