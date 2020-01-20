#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hexaNum, digit, storingNum;
    printf("Please input a hexadecimal number: ");  scanf("%x", &hexaNum);
    storingNum=hexaNum;
    while(hexaNum!=0)
    {
        digit=hexaNum%10;
        hexaNum=hexaNum/10;
        printf("\n These are the digits: %x", digit);
    }
    return 0;
}
