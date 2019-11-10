#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//I will use the symbols for Roman numerals: I,V,X,L,C,D,M;
//In this way, the biggest number that can be obtain would be: 3999;
//The longest length for the string would be 15 characters: number (MMMDCCCLXXXVIII->3888)

int main()
{   int i,sign,ok,j,p,k,NumericValue[7]={1,5,10,50,100,500,1000},NewNumber=0;
    char Characters[7]={"IVXLCDM"};
    char NumberRoman[16];
    scanf("%s",&NumberRoman);
    i=0;
    while (i<strlen(NumberRoman))
    {
        j=i;
        p=0;
        while(i<strlen(NumberRoman)&&NumberRoman[i]==NumberRoman[j])
        { i++;
          p++;
        }
        ok=1;
        sign=0;
    for(k=6;k>=0&&ok==1;k--)
    {
        if(Characters[k]==NumberRoman[i])
        {
         sign=1;
        }
        if(Characters[k]==NumberRoman[j])
        {
            ok=0;
            if(sign==1) {NewNumber=NewNumber-NumericValue[k];}
            else {NewNumber=NewNumber+p*NumericValue[k];}
        }
    }

    }
    printf("%d",NewNumber);
    return 0;
}
