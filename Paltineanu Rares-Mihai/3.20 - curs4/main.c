/** Read a sentence from the standard input. Compute the number of the words and find and display the longest one.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sizeOfAux(char *aux){
    int i = 0;
    while(aux[i] != NULL) {
        i++;
    }
    return i;
}

int main()
{
    int maximLength = -1, ctWords = 0;
    char s[200], word[200], *aux;
    memset(s, '\0', sizeof(s)); memset(word, '\0', sizeof(word));
    gets(s);
    aux = strtok(s, " ");

    while(aux != NULL) {
        ctWords++;
        if(sizeOfAux(aux) > maximLength) { /// i dont understant why i cant use strlen(aux)
            strcpy(word, aux);
            maximLength = sizeOfAux(aux);
        }

        aux = strtok(NULL, " ");
    }

    printf("The number of words is:%d; the longest word is: %s", ctWords, word);
    return 0;
}
