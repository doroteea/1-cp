/**Write a function to check whether a character string is a substring of another character string.
The function should return the position at which the substring starts if true, or –1 otherwise.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substringInString(char *s1, char *s2) {

    int size1 = strlen(s1), size2 = strlen(s2), ct = 0, pos;
    for(int i = 0; i < size1; i++) {
        if(s1[i] == s2[0]) {
            pos = i;
            while(i < size1 && ct < size2 && s1[i] == s2[ct] ) {
                i++;
                ct++;
            }
            if(ct == size2)
                return pos;
            else
                ct = 0;
        }
    }

    return -1;
}

int main() {

    char *s1 = (char*)malloc(sizeof(char) * 50);
    char *s2 = (char*)malloc(sizeof(char) * 50);
    gets(s1); gets(s2);
    if(strlen(s1) > strlen(s2)) {
        printf("The position is: %d.", substringInString(s1, s2));
    }
    else {
        printf("The position is: %d.",substringInString(s2, s1));
    }

    return 0;
}
