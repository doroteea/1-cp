#include <stdio.h>
#include <stdlib.h>
#define MAX_SENTENCE_LENGTH 200
#define NUMBER_OF_LETTERS_IN_ALPHABET 26

typedef struct
{
    char letter;
    int occurence;
} letterOccurence;

int isUppercase(char currentLetter)
{
    return currentLetter >= 65 && currentLetter <= 90;
}

int isLowercase(char currentLetter)
{
    return currentLetter >= 97 && currentLetter <= 122;
}

int isPartOfAlphabet(char currentLetter)
{
    return isUppercase(currentLetter) || isLowercase(currentLetter);
}

char toLowercase(char letter)
{
    return letter - 32;
}

char ** readSentences(FILE * f, int numberOfSentences)
{
    char ** sentences = (char**)malloc(sizeof(char**)*numberOfSentences);

    for(int i=0; i<numberOfSentences; i++)
    {
        sentences[i] = (char*)malloc(sizeof(char)*MAX_SENTENCE_LENGTH);
        fgets(sentences[i],MAX_SENTENCE_LENGTH,f);
    }

    return sentences;
}

void fillLetterOccurencesForSentence(char * sentence, letterOccurence * letters)
{
    int j=0;
    char currentLetter = sentence[j];
    while(isPartOfAlphabet(currentLetter))
    {
        if(isUppercase(currentLetter))
        {
            currentLetter = toLowercase(currentLetter);
        }
        letters[currentLetter - 97].occurence += 1;
        currentLetter = sentence[++j];
    }
}

void fillLetterOccurences(letterOccurence * letters, char ** sentences, int numberOfSentences)
{
    for(int i=0; i<numberOfSentences; i++)
    {
        fillLetterOccurencesForSentence(sentences[i], letters);
    }
}

void initializeLetterOccurence(letterOccurence * letters)
{
    for(int i=0; i<NUMBER_OF_LETTERS_IN_ALPHABET; i++)
    {
        letters[i].letter = i + 97;
        letters[i].occurence = 0;
    }
}

void printLetterOccurences(letterOccurence * letters)
{
    for(int i=0; i<NUMBER_OF_LETTERS_IN_ALPHABET; i++)
    {
        printf("%c = %d\n", letters[i].letter, letters[i].occurence);
    }
}

void sortLetterOccurences(letterOccurence * letters)
{
    for(int i=0; i<NUMBER_OF_LETTERS_IN_ALPHABET; i++)
    {
        for(int j=i; j<NUMBER_OF_LETTERS_IN_ALPHABET; j++)
        {
            if(letters[i].occurence < letters[j].occurence)
            {
                letterOccurence aux = letters[i];
                letters[i] = letters[j];
                letters[j] = aux;
            }
        }
    }
}

int computeScoreForSentenceBattle(char * sentence1, char * sentence2)
{
    letterOccurence * sentenceOneLetters = (letterOccurence*)malloc(sizeof(letterOccurence)*NUMBER_OF_LETTERS_IN_ALPHABET);
    initializeLetterOccurence(sentenceOneLetters);

    letterOccurence * sentenceTwoLetters = (letterOccurence*)malloc(sizeof(letterOccurence)*NUMBER_OF_LETTERS_IN_ALPHABET);
    initializeLetterOccurence(sentenceTwoLetters);

    fillLetterOccurencesForSentence(sentence1, sentenceOneLetters);
    fillLetterOccurencesForSentence(sentence2, sentenceTwoLetters);

    int score=0;
    for(int i=0; i<NUMBER_OF_LETTERS_IN_ALPHABET; i++) {
        if(sentenceOneLetters[i].occurence == sentenceTwoLetters[i].occurence) {
            score += 1;
        } else {
            score -= 1;
        }
    }
    return score;
}

void printLetterBattle(char ** sentences, int numberOfSentences, int sIndex)
{
    for(int i=0; i<numberOfSentences; i++)
    {
        int score = computeScoreForSentenceBattle(sentences[sIndex], sentences[i]);
        printf("%d vs. %d = %d\n", i, sIndex, score);
    }
}

int main()
{
    FILE * f = fopen("sentences.dat", "r");
    FILE * o = fopen("sentences.dat", "rw+");
    int numberOfSentences;
    fscanf(f,"%d\n",&numberOfSentences);

    char ** sentences = readSentences(f, numberOfSentences);

    letterOccurence * letters = (letterOccurence*)malloc(sizeof(letterOccurence)*NUMBER_OF_LETTERS_IN_ALPHABET);
    initializeLetterOccurence(letters);
    fillLetterOccurences(letters,sentences, numberOfSentences);
    sortLetterOccurences(letters);
    printLetterOccurences(letters);
    printLetterBattle(sentences, numberOfSentences, 5);

    return 0;
}
