#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

char * substring(char * s, int pos, int length) {
    char * subs = (char * ) malloc(sizeof(char) * 55);
    strncpy(subs, s + pos, length);
    subs[length] = '\0';
    return subs;
}

char * addSubs(char * s, char * subs, int pos) {
    char * aux = (char * ) malloc(sizeof(char) * 55);
    int l = strlen(subs);
    strcpy(aux, s + pos);
    strcpy(s + pos, subs);
    strcpy(s + pos + l, aux);
    return s;
}

char * deleteSubs(char * s, int pos, int length) {
    char * subs = (char * ) malloc(sizeof(char) * 55);
    strcpy(subs, s + pos + length);
    strcpy(s + pos, subs);
    return s;
}

int isSubs(char * s, char * subs) {
    int l = strlen(s), lsubs = strlen(subs), i;
    for (i = 0; i < l - lsubs + 1; i++) {
        if (strncmp(s + i, subs, lsubs) == 0)
            return i;
    }
    return -1;
}

char * float2char(float x) {
    char * s = (char * ) malloc(sizeof(char) * 55);
    sprintf(s, "%f", x);
    return s;
}

int char2float(char * s) {
    float x = 0;
    int l = strlen(s), i, pointFound = 0;
    int digitsAfterPoint = 0;
    for (i = 0; i < l; i++) {
        if (s[i] != '.' && pointFound == 0) {
            x = x * 10 + s[i] - '0';
        } else {
            if (s[i] == '.') {
                pointFound = 1;
            } else {
                digitsAfterPoint++;
                float d = s[i] - '0';
                d = d / (pow(10, digitsAfterPoint));
                printf("%f\n", d);
                x = x + d;
            }
        }
    }

    return x;
}

int main() {
    char * s = (char * ) malloc(sizeof(char) * 55);
    char * subs = (char * ) malloc(sizeof(char) * 55);
    int pos, length;
    //3.2
    scanf("%s", s);
    getchar();
    scanf("%d", & pos);
    scanf("%d", & length);
    subs = substring(s, pos, length);
    printf("%s", subs);
    //3.3
    scanf("%s", s);
    getchar();
    scanf("%s", subs);
    getchar();
    scanf("%d", & pos);
    s = addSubs(s, subs, pos);
    printf("%s", s);
    //3.4
    scanf("%s", s);
    getchar();
    scanf("%d", & pos);
    scanf("%d", & length);
    s = deleteSubs(s, pos, length);
    printf("%s", s);
    //3.5
    scanf("%s", s);
    getchar();
    scanf("%s", subs);
    getchar();
    if (isSubs(s, subs) == -1) {
        printf("it's not substring");
    } else {
        printf("it's substring beginning on pos %d", isSubs(s, subs));
    }
    //3.6
    float x;
    scanf("%f", & x);
    s = float2char(x);
    printf("%s\n", s);
    x = char2float(s);
    printf("%f", x);
    return 0;
}
