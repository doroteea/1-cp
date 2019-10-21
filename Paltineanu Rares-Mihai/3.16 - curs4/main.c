/**Given two strings of n and m integer elements,  compute:
a) The string that contains all the elements belonging to both strings.
b)The string of all the elements of the two given strings, written once.
c) The string of the elements from the first string, without the elements that are also in the second string.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;

void read(char *s1, char *s2) {

    for(int i = 0; i < n; i++) {
        scanf("%c", &s1[i]);
    }

    s1[n] = '\0';

    getchar();

    for(int i = 0; i < m; i++) {
        scanf("%c", &s2[i]);
    }

    s2[m] = '\0';

}

int searchChar(char s[200], char character, int size) {

    int ct = 0;

    for(int i = 0; i < size; i++) {

        if(s[i] == character) {
            ct++;
        }

    }

    return ct;

}

void newStringA(char s1[], char s2[], char *s3) {

    char V[200]; /// i am using this vector to save the elements belonging to both strings,
                 /// for ex if i find a character in both string, after this i wont put it anymore if there are more same characters
    int lengthV, length = 0, temporary;

    for(int i = 0; i < m; i++) {

        if(strchr(s1, s2[i]) != NULL && strchr(V, s2[i]) == NULL) {

            temporary = searchChar(s1, s2[i], n) + searchChar(s2, s2[i], m); /// temporary is the number of elements in both strings

            for(int j = 0; j < temporary; j++) {
                s3[length] = s2[i];
                length++;
            }

            V[lengthV] = s2[i];
            lengthV++;

        }

    }

    s3[length] = '\0';

}

void newStringB(char s1[], char s2[], char *s3) {

    int length = 0;

    for(char a = 1; a < 127; a++) {

        if(strchr(s1, a) != NULL && strchr(s2, a) != NULL) {
            s3[length] = a;
            length++;
        }

    }

    s3[length] = '\0';

}

void newStringC(char s1[], char s2[], char *s3) {

    int length = 0;

    for(int i = 0 ; i < n; i++) {

        if(strchr(s2, s1[i]) == NULL) {
            s3[length] = s1[i];
            length++;
        }

    }

    s3[length] = '\0';

}

int main() {

    printf("Read n and m: ");
    scanf("%d %d", &n, &m);
    char s1[n], s2[m], s3[n + m];
    getchar();
    printf("Read the strings: ");
    read(s1, s2);

    /// a !!!!!!!!!!!!!!!!!
    newStringA(s1, s2, s3);

    if(s3[0] == '\0') {
        printf("There are no common elements in the strings\n");
    } else {
        printf("The string that contains all the elements belonging to both strings is: %s\n", s3);
    }

    /// b !!!!!!!!!!!!!!!!!
    newStringB(s1, s2, s3);

    if(s3[0] == '\0') {
        printf("There are no common elements in the strings\n");
    } else {
        printf("The string of all the elements of the two given strings, written once is:%s\n", s3);
    }

    /// c !!!!!!!!!!!!!!!!!
    newStringC(s1, s2, s3);

    if(s3[0] == '\0') {
        printf("There are no different elements in the strings\n");
    } else {
        printf("The string of the elements from the first string, without the elements that are also in the second string is:%s\n", s3);
    }
    return 0;
}
