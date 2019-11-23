#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *initial_String;
char *sub_String;

void subString(char s[], char sub[], int p, int l){
    int c=0;

    while (c<l){
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}
int main() {
    int posi,len;
    initial_String = (char*)malloc(30*sizeof(char));
    sub_String = (char*)malloc(30* sizeof(char));
    printf("Hi! Enter the starting position and length:");
    scanf("%d,%d", &posi,&len);
    printf("Now input your string");
    scanf("%s[^\n]",initial_String);
    subString(initial_String, sub_String, posi, len);

    printf ("%s",sub_String);

    return 0;
}