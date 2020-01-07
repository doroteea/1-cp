#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int frequency;
    int ascii;
} letterType;

char *readData(FILE *input, letterType *letterArray, int m)
{
    int nrSentences, i;
    fscanf(input,"%d",&nrSentences);

    char *mString = (char*)malloc(sizeof(char)*30);

    char *strbuf = (char*)malloc(sizeof(char)*30);
    for(i=0; i<26; i++)
    {
        letterArray[i].frequency = 0;
        letterArray[i].ascii = 'a' + i;
    }

    fgets(strbuf,30,input);
    for(i=1; i<=nrSentences; i++)
    {
        fgets(strbuf,30,input);

        int length = strlen(strbuf);
        int place;

        int j;
        for(j=0; j<length-1; j++)
        {
            place = strbuf[j] - 'a';
            letterArray[place].frequency++;
        }

        if(i == m+1)
        {
            strcpy(mString,strbuf);
        }
    }

    return mString;
}

letterType *sort(letterType *letterArray)
{
    int i,j;
    for(i=0; i<25; i++)
    {
        for(j=i; j<26; j++)
        {
            if(letterArray[i].frequency < letterArray[j].frequency)
            {
                letterType aux;
                aux = letterArray[i];
                letterArray[i] = letterArray[j];
                letterArray[j] = aux;
            }
        }
    }
    return letterArray;
}

void print(letterType *letterArray, FILE *output)
{
    int i;
    for(i=0; i<26; i++)
    {
        char c;
        c = (char)letterArray[i].ascii;

        fprintf(output,"%c = %d\n",c,letterArray[i].frequency);
    }
}

void compareSentences(FILE *input, int m, int nrSentences, int *comparationArray, char *mString)
{
    int i;

    char *strbuf = (char*)malloc(sizeof(char)*30);
    fgets(strbuf,30,input);

    for(i=1; i<=nrSentences; i++)
    {
        fgets(strbuf,30,input);

        printf("SENTENCE %d:\n\t %s \n",i,strbuf);


        int j;
        for(j=0; j<26; j++)
        {
            char letter;
            letter = (char)j + 'a';
            int appearanceInM = 0, appearanceInOther = 0;

            int lengthOther  = strlen(strbuf);
            int lengthMString = strlen(mString);

            int a;
            for(a=0; a<lengthOther; a++)
            {
                if(strbuf[a] == letter)
                {
                    appearanceInOther++;
                }
            }

            for(a=0; a<lengthMString; a++)
            {
                if(mString[a] == letter)
                {
                    appearanceInM++;
                }
            }

            if(appearanceInM == appearanceInOther)
            {
                comparationArray[i]++;
            }
            else
            {
                comparationArray[i]--;
            }
        }

    }

}

void printComparation(FILE *output, int m, int nrSentences, int *comparationArray)
{
    int i;
    fprintf(output,"\n");
    for(i=1; i<=nrSentences; i++)
    {


        fprintf(output,"%d vs. %d = %d\n",i-1,m,comparationArray[i]);

    }
}

int main()
{
    FILE *input;
    input = fopen("Sentences.dat","r");

    FILE *output;
    output = fopen("Output.dat","r+");

    int m;
    printf("Input m: ");
    scanf("%d",&m);

    char *mString = (char*)malloc(sizeof(char)*30);

    ///first

    letterType *letterArray = (letterType*)malloc(sizeof(letterType)*26);

    mString = readData(input,letterArray,m);

    letterArray = sort(letterArray);

    print(letterArray,output);

    printf("%s",mString);

    ///second

    fclose(input);

    input = fopen("Sentences.dat","r");

    int nrSentences;
    fscanf(input,"%d",&nrSentences);

    int *comparationArray = calloc(sizeof(int),nrSentences);

    compareSentences(input,m,nrSentences,comparationArray,mString);

    printComparation(output,m,nrSentences,comparationArray);

    return 0;
}
