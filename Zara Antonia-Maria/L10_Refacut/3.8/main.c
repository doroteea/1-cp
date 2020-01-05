/** 3.8.Read a character string composed of only letters and digits.
       Find the occurrence frequencies of the characters of the string using a list,
       ordered alphabetically (a node contains a character, the occurrence
       frequency and the address of the next node).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char character;
    int frequency;
}characterType;

char *readString()
{
    char *string = (char*)malloc(sizeof(char)*100);
    printf("Input string with lowercase and digits: ");
    scanf("%s",string);

    return string;
}

characterType *assignCharacters()
{
    characterType *characters = (characterType*)malloc(sizeof(characterType)*37);

    int i;
    for(i=0; i<10; i++)
    {
        characters[i].character = i + '0';
    }
    for(i=10; i<36; i++)
    {
        characters[i].character = i - 10 + 'a';
    }

    for(i=0; i<36; i++)
    {
        characters[i].frequency = 0;
    }

    return characters;
}

characterType *findFrequencies(char *string, characterType *characters)
{
    int length = strlen(string);
    int i;

    for(i=0; i<length; i++)
    {
        int position = 0;
        if(string[i] >= '0' && string[i] <= '9')
        {
            position = string[i] - (int)'0';
        }
        else
        {
            position = string[i] + 10 - (int)'a';
        }
        characters[position].frequency++;
    }

    return characters;
}

void printFrequencies(characterType *characters)
{
    int i;
    for(i=0; i<36; i++)
    {
        printf("\nThe frequency of %c is %d.",characters[i].character,characters[i].frequency);
    }
}

int main()
{
    char *string = (char*)malloc(sizeof(char)*100);
    characterType *characters = (characterType*)malloc(sizeof(characterType)*37);

    string = readString();

    characters = assignCharacters();

    characters = findFrequencies(string,characters);

    printFrequencies(characters);

    return 0;
}
