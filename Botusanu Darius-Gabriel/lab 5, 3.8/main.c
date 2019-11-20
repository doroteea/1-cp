#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*still working on it*/
void motherRome(int *number)
{
    int i;
    char romanNumbers[14][2]= {"M",
                          "CM",
                          "D",
                          "CD",
                          "C",
                          "XC",
                          "L",
                          "XL",
                          "X",
                          "IX",
                          "V",
                          "IV",
                          "I"
                         };
     int arabianNumbers[14]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
     char romanized='\0';
     for(i=0;i<14;i++)
     {
         while(arabianNumbers[i]<=*number)
         {
             romanized+=romanNumbers[i];
             *number-=arabianNumbers[i];
         }
     }
     printf("%c",romanized);
}

int main()
{
    int number;
    printf("Please input the number you wish to convert: ");
    scanf("%d",&number);
    if(number>=4000)
    {
        printf("\nThe number is out of range!");
        return 0;
    }
    else
    {
        motherRome(&number);
    }
    return 0;
}
