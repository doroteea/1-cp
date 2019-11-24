#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main() {
    int n, i, length, length_max = 0, sum, summax = 0, j;
    char * s = (char * ) malloc(sizeof(char) * 55);
    char * longest = (char * ) malloc(sizeof(char) * 55);
    char * biggest = (char * ) malloc(sizeof(char) * 55);
    scanf("%d", & n);
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        // getchar ();
        length = strlen(s);
        if (length > length_max) {
            strcpy(longest, s);
            length_max = length;
        }
        sum = 0;
        for (j = 0; j < length; j++) {
            sum += s[j];
        }
        if (sum > summax) {
            strcpy(biggest, s);
            summax = sum;
        }
    }
    printf("the longest string is %s", longest);
    printf("\nthe biggest string is %s", biggest);
    return 0;
}
