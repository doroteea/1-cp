/* N sentences are read from a file.
 * - find the number of occurrences of each letter of the alphabet in all sentences, sort them and print the result
 * to a file Output.dat
 * - a number m is read from the keyboard representing a sentence number (assume 0<m<=N). Compare sentence m with
 * each other sentence such that, for each letter of the alphabet, if the letter appears the same number of times
 * in sentence A and B, the comparison gets +1 points, else, it gets -1 points. Output the outcome of the comparison
 * as exemplified below. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letter;
    int occurence;
} letterOccurrence;

void initializeLetterOccurence(letterOccurrence *letters) {
    for (int i = 0; i < 26; i++) {
        letters[i].letter = i + 97;
        letters[i].occurence = 0;
    }
}

char **readFile(FILE *f, int n) {
    char *sentence = (char *) malloc(sizeof(char) * 100);

    char **sentenceMatrix = (char **) malloc(sizeof(char *) * 30);
    for (int i = 0; i < 30; i++) {
        *(sentenceMatrix + i) = (char *) malloc(sizeof(char) * 100);
    }

    int j = 0;
    for (int i = 0; i <= n; i++) {
        fgets(sentence, 100, f);
        char *pch;
        pch = strtok(sentence, "\n");
        while (pch != NULL) {
            strcpy(sentenceMatrix[j], pch);
            j++;
            pch = strtok(NULL, "\n");
        }
    }

    return sentenceMatrix;
}

int compareSentences(char *s1, char *s2) {
    letterOccurrence *sentenceOneLetters = (letterOccurrence *) malloc(sizeof(letterOccurrence) * 26);
    initializeLetterOccurence(sentenceOneLetters);

    letterOccurrence *sentenceTwoLetters = (letterOccurrence *) malloc(sizeof(letterOccurrence) * 26);
    initializeLetterOccurence(sentenceTwoLetters);

    for (int i = 0; i < strlen(s1); i++) {
        char currentLetter = s1[i];
        sentenceOneLetters[currentLetter - 'a'].occurence += 1;
        sentenceOneLetters[currentLetter - 'a'].letter = currentLetter;
    }

    for (int i = 0; i < strlen(s2); i++) {
        char currentLetter = s2[i];
        sentenceTwoLetters[currentLetter - 'a'].occurence += 1;
        sentenceTwoLetters[currentLetter - 'a'].letter = currentLetter;
    }

    int score = 0;
    for (int i = 0; i < 26; i++) {
        if (sentenceOneLetters[i].occurence == sentenceTwoLetters[i].occurence) {
            score += 1;
        } else {
            score -= 1;
        }
    }

    return score;
}

void writeStructure(letterOccurrence *letters, int n, char **sentenceMatrix)
{
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < strlen(sentenceMatrix[i]); k++) {
            char currentLetter = sentenceMatrix[i][k];
            letters[currentLetter - 'a'].occurence += 1;
            letters[currentLetter - 'a'].letter = currentLetter;
        }
    }
}

void sortOccurrences(letterOccurrence *letters)
{
    for (int i = 0; i < 26 - 1; i++) {
        for (int k = i + 1; k < 26; k++) {
            if (letters[i].occurence < letters[k].occurence) {
                int aux = letters[i].occurence;
                letters[i].occurence = letters[k].occurence;
                letters[k].occurence = aux;

                char auxi = letters[i].letter;
                letters[i].letter = letters[k].letter;
                letters[k].letter = auxi;
            }
        }
    }

}

int main() {
    FILE *f;
    f = fopen("sentences.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    char **sentenceMatrix = readFile(f, n);

    letterOccurrence *letters = (letterOccurrence *) malloc(sizeof(letterOccurrence) * 26);
    writeStructure(letters,n,sentenceMatrix);
    sortOccurrences(letters);

    FILE *of;
    of = fopen("output.txt", "w");
    fprintf(of, "A)\n");
    for (int i = 0; i < 26; i++) {
        fprintf(of, "%c = %d\n", letters[i].letter, letters[i].occurence);
    }

    int m;
    printf("Please type a number m representing a sentence number: ");
    scanf("%d", &m);

    fprintf(of, "\nB)\n");
    for (int i = 0; i < n; i++) {
        int score = compareSentences(sentenceMatrix[i], sentenceMatrix[m]);
        fprintf(of, "%d vs %d: %d\n", i, m, score);
    }

    fclose(f);
    fclose(of);
    return 0;
}