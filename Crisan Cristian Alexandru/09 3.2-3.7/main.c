#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*3.2. Write a function to extract, from a source string,
 a substring identified by the position in the source string
 and by the length expressed as a number of characters.

3.3. Write a function to insert a source character string
in a destination character string, at a given position.

3.4. Write a function to delete a substring
from a given character string, specifying
the beginning position and the length of the substring.

3.5. Write a function to verify if a given string
is a substring of another character string.
 If it is, specify the beginning position of the substring.

3.6. Write two functions, the first to convert an integer
 or real number into a string of characters,
  and the second to perform the inverse operation.

3.7. Write a program to read n strings of characters
and display both the longest string
 and the biggest one as seen as an alphanumeric sequence. */
char * ExtractSubstringPosAndLenght(char *String,int Position,int Lenght)
{
    /*If you want to return a char* from a function, make sure you malloc() it.
    Stack initialized character arrays make no sense in returning,
    as accessing them after returning from that function is undefined behavior.*/
    char *substring=(char*)malloc(sizeof(char)*Lenght);
    strncpy(substring,String+Position,Lenght);
    substring[Lenght]='\0';
    return substring;
}
void InsertStringInStringAtPos(char *CharactStrDest,char *CharactStrToCopy,int Position)
{
    char *aux=(char*)malloc(sizeof(char)*(strlen(CharactStrDest+Position)));
    strcpy(aux,CharactStrDest+Position);
    strcpy(CharactStrDest+Position,CharactStrToCopy);
    strcat(CharactStrDest,aux);

}
void DeleteSubstring(char *String,int Position,int Lenght)
{
    strcpy(String+Position,String+Position+Lenght);
}
int VerifyInclusion(char *String,char *StringSearched)
{
    char *aux=(char*)malloc(sizeof(char)*strlen(StringSearched));
    if(strlen(StringSearched)>strlen(String))
    {
        return -2;
    }
    else
    {
        int i=0;
        while(i<=(strlen(String)-strlen(StringSearched)))
        {
            if(String[i]==StringSearched[0])
            {

                strncpy(aux,String+i,strlen(StringSearched));
                aux[strlen(StringSearched)]='\0';
                if(strcmp(aux,StringSearched)==0)
                {
                    return i;
                }
            }
            i++;

        }

        if(i==(strlen(String)-strlen(StringSearched)+1));
        {
            return -1;
        }
    }

}
void ReverseArray(char *Array,int Lenght)
{
    char aux;
    for(int i=0; i<Lenght/2; i++)
    {
        aux=Array[i];
        Array[i]=Array[Lenght-1-i];
        Array[Lenght-1-i]=aux;
    }
}
char * intToArray(int Number)
{
    char *Array=(char*)malloc(sizeof(char)*10);
    int ArrayLenght=0;
    while(Number>0)
    {
        Array[ArrayLenght]=Number%10+48;
        ArrayLenght++;
        Number=Number/10;
    }
    Array[ArrayLenght]='\0';
    ReverseArray(Array,ArrayLenght);

    return Array;
}
int arrayToInt(char *Array,int Lenght)
{
    int newNumber=0;
    for(int i=0; i<Lenght; i++)
    {
        newNumber=newNumber*10+(int)Array[i]-48;
    }
    return newNumber;
}
int main()
{
    char string[100],string2[100];
    int Position,Lenght,Number,Choice;
    printf("Which exercise do you want to be solved?\nGive its number(from 2 to 7):");
    scanf("%d",&Choice);
    switch(Choice)
    {
    case 2:
    {
        printf("3.2\nGive the character string:");
        //gets(string);
        scanf("%s",&string);
        printf("Give the position:");
        scanf("%d",&Position);
        printf("Give the lenght:");
        scanf("%d",&Lenght);
        printf("%s",ExtractSubstringPosAndLenght(string,Position,Lenght));
        break;
    }
    case 3:
    {
        printf("3.3\nGive the source character string:");
        //gets(string);
         scanf("%s",&string);
        printf("Give the destination character string:");
        //gets(string2);
         scanf("%s",&string2);
        printf("Give the position:");
        scanf("%d",&Position);
        InsertStringInStringAtPos(string2,string,Position);
        printf("%s",string2);
        break;
    }
    case 4:
    {
        printf("3.4\nGive the character string:");
        //gets(string);
         scanf("%s",&string);
        printf("Give the position:");
        scanf("%d",&Position);
        printf("Give the lenght:");
        scanf("%d",&Lenght);
        DeleteSubstring(string,Position,Lenght);
        printf("%s",string);
        break;
    }
    case 5:
    {
        printf("3.5\nGive the string in which we are searching:");
        //gets(string);
         scanf("%s",&string);
        printf("Give the searched string:");
        //gets(string2);
         scanf("%s",&string2);
        Position=VerifyInclusion(string,string2);
        if(Position==-1)
        {
            printf("The string %s has not been found as being a substring of %s.",string2,string);

        }
        else
        {
            if(Position==-2)
            {
                printf("The lenght of the searched string is bigger than the one of the string we are searching in!");
            }
            else
            {
                printf("%s is a substring of %s,found at position %d",string2,string,Position);
            }
        }
        break;

    }
    case 6:
    {
        printf("3.6.1 Give the number:");
        scanf("%d",&Number);
        printf("%s",intToArray(Number));
        printf("3.6.2 Give the string:");
        scanf("%s",&string);
        printf("%d",arrayToInt(string,strlen(string)));
        break;
    }
    case 7:
    {
        printf("3.7\n");
        longestAndBiggestSequence();
        break;
    }
    default:
        printf("Error!\nExercise number not found!");
    }


    return 0;
}
