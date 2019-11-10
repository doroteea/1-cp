#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extractString(char *s, char *newVect, int pos, int length) {

    int sizeNewVect = 0;

    for(int i = pos; i < pos + length; i++) {

        newVect[sizeNewVect++] = s[i];

    }

    newVect[sizeNewVect] = '\0';

}

void insert(char *s2, char *dest, int pos) {

    int n1 = strlen(dest);
    int n2 = strlen(s2);

    int k = 0;

    for(int i = n1 - 1; i >= pos; i--) {

        dest[i + n2] = dest[i];

    }

    for(int i = pos; i < pos + n2; i++) {

        dest[i] = s2[k];
        k++;

    }

    dest[n1 + n2] = '\0';
    puts(dest);

}

void deleteSubstring(char *s, int pos, int length) {

    for(int i = pos; i < pos + length; i++) {

        strcpy(s + pos, s + pos + 1);

    }

}

int substringInString(char *sub, char *s) {

    int sizesub = strlen(sub);
    int sizestring = strlen(s);

    int i = 0, j = 0;
    int gasit = 0;

    while( i < sizesub && j < sizestring) {

        if(s[j] != sub[i]) {

            j++;

        } else {

            gasit = j;

            while(i < sizesub && j < sizestring && s[j] == sub[i]) {

                j++;
                i++;

            }

        }

        if(i != sizesub) {

            i = 0;
            gasit = 0;

        }
    }

    return gasit;
}

void intToString(int nr, char *nrs) {

    int sizeString = 0;

    while(nr != 0) {

        nrs[sizeString++] = nr%10 + '0';
        nr /= 10;

    }

    nrs[sizeString] = '\0';

}

int verify(char *s) {

    int size = strlen(s);

    for(int i = 0; i < size; i++) {
        if(!(s[i] >= '0' && s[i] <= '9')) {

            return 0;

        }
    }

    return 1;

}

void stringToInt(int *nr, char *s) {

    int size = strlen(s);

    for(int i = 0; i < size; i++) {

        *nr = *nr * 10 + (s[i] - '0');

    }

}

void readString(char **mat, int n) {

    for(int i = 0; i < n; i++) {

        gets(mat[i]);

    }

}

int longestString(char **mat, int n) {

    int pos = -1, maxim = 0;

    for(int i = 0; i < n; i++) {

        if(strlen(mat[i]) > maxim) {

            pos = i;
            maxim = strlen(mat[i]);

        }

    }

    return pos;
}

int biggestString(char **mat, int n) {

    int ct = 0;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(i != j) {

                if(strcmp(mat[i], mat[j]) > 0) {

                    ct++;

                }

            }
        }

        if(ct == n - 1) {

            return i;

        }

        ct = 0;
    }

}

int main() {

    ///Write a function to extract, from a source string, a substring identified by the position in the source string
    ///and by the length expressed as anumber of characters.

    printf("Problem 3.2\n");

    char *s1 = (char *)malloc(sizeof(char) * 151);

    char *newVect= (char *)malloc(sizeof(char) * 151);

    int pos, length, sizeNewVect = 0;

    printf("Read the string: ");
    gets(s1);

    printf("Read the position and the length: ");
    scanf("%d %d", &pos, &length);
    getchar();

    extractString(s1, newVect, pos, length);
    printf("The new string is: ");
    puts(newVect);



    ///Write  a  function  to  insert  a  source  character  string  in  a  destination  character string, at a  given position.

    printf("\n\nProblem 3.3\n");

    char *s2 = (char *)malloc(sizeof(char) * 101);

    char *destination = (char *)malloc(sizeof(char) * 202);

    int pos1;

    printf("Read the source string: "); gets(s2);
    printf("Read the destination string: "); gets(destination);
    printf("Read the position: "); scanf("%d", &pos1); getchar();

    printf("The new string is: ");
    insert(s2, destination, pos1);



    ///Write  a  function  to  delete  a  substring  from  a  given  character  string,
    ///specifying  the  beginning position and the length of the substring

    printf("\n\nProblem 3.4\n");

    char *s3 = (char *)malloc(sizeof(char) * 151);

    int pos2, length1;

    printf("Read the string: "); gets(s3);
    printf("Read the position and the length: ");
    scanf("%d %d", &pos2, &length1);
    getchar();

    deleteSubstring(s3, pos2, length1);
    printf("The new string is: ");
    puts(s3);



    ///Write a function to verify if a given string is a substring of another character string.
    ///If it is, specify the beginning position of the substring

    printf("\n\nProblem 3.5\n");

    char *s4 = (char *)malloc(sizeof(char) * 150);
    char *sub = (char *)malloc(sizeof(char) * 150);

    printf("Read the character string: ");
    gets(s4);

    printf("Read the substring: ");
    gets(sub);

    if(substringInString(sub, s4) != 0) {
        printf("The beginning position of the substring is: %d", substringInString(sub, s4));
    }
    else {
        printf("No substring.");
    }



    /// Write two functions, the first to convert an integer or real number into a string of characters,
    ///and the second to perform the inverse operation.

    printf("\n\nProblem 3.6\n");


    /// int to string

    int nr1;

    char *nrToString = (char *)malloc(sizeof(char) * 12);

    printf("Read the number: ");
    scanf("%d", &nr1);
    getchar();

    intToString(nr1, nrToString);
    strrev(nrToString);
    printf("The number as a string is: ");
    puts(nrToString);


    /// string to int

    char *stringToNr = (char *)malloc(sizeof(char) * 12);

    int nr2 = 0;

    printf("Read the string as a number: ");
    gets(stringToNr);

    if(verify(stringToNr) == 0) {

        printf("The string can not be converted into a number.");

    } else {

        stringToInt(&nr2, stringToNr);
        printf("The string as a number is: %d", nr2);

    }



    ///Write a program to read n strings of characters and display both the longest string
    ///and the biggest one as seen as an alphanumeric sequence.

    printf("\n\nProblem 3.7\n");

    int n;
    printf("Read the value of n: "); scanf("%d", &n);
    getchar();

    char **mat = (char **)malloc(sizeof(char *) * n);

    for(int i = 0; i < n; i++) {
        mat[i] = (char *)malloc(sizeof(char) * 101);
    }

    printf("Read %d strings: ", n);
    readString(mat, n);

    printf("The longest string is: "); puts(mat[longestString(mat, n)]);

    printf("The biggest string as an alphanumeric sequence is: "); puts(mat[biggestString(mat, n)]);
    return 0;
}
