/**
Write a program which should read a C source text file
and prints the occurrence frequencies for the reserved keywords in the given text.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vect[128];

void count(char *txt) {

    int n = strlen(txt);

    for(int i = 0; i < n; i++) {

        vect[*(txt + i) - 0]++;

    }
}

void printFreq() {

    for(int i = 33; i < 128; i++) {

        printf("%c - %d\n", i, vect[i]);

    }

}
int main() {
    FILE *file1;
    file1 = fopen("12.txt", "r");

    if(file1 == NULL) {

        return -1;

    }
    char *text = (char *)malloc(200);
    fgets(text, 200, file1);

    count(text);

    printFreq();
    return 0;
}
