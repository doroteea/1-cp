#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define SIZE 50
/*I do not know why it stops after submitting the strings*/
void checkSub(char *string, char *substring)
{
    int i, j=0, checkingNumber=0, contoring=-1;
    for(i=0;i<strlen(string);i++)
    {
        while(j<=strlen(substring))
        {
            if(string[i]==substring[j])
            {
                checkingNumber+=1;
                j++;
            }
            else
            {
                contoring+=1;
            }
        }
    }
    if(checkingNumber==strlen(substring))
    {
        printf("\nIt is a substring and it starts from the position %d",contoring);
    }
    else
    {
        printf("\nIt is not a substring");
    }
}

int main()
{
    char *string=(char*)malloc(sizeof(char)*SIZE);
    char *substring=(char*)malloc(sizeof(char)*SIZE);
    printf("Please enter a string:");
    gets(string);
    printf("\nPlease enter another string:");
    gets(substring);

    checkSub(string, substring);
    return 0;
}
