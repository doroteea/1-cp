#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteSubString(char string[],int position,int length)
{
    strcpy(string+position,string+position+length);

}
int main()
{
    char string[20];
    int position,length;
    printf("Enter string: ");
    gets(string);
    printf("Enter position and length: ");
    scanf("%d %d",&position,&length);
    deleteSubString(string,position,length);
    puts(string);

    return 0;
}
