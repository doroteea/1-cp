#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void substring(char s[], char sub[], int p, int l){
    int c=0;

    while (c<l){
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
}
int main() {
    int posi,len;
    char initial_String[30];
    char sub_String[30];
    printf("Hi! Enter the position from which you want the substring to start and it's length");
    scanf("%d,%d", &posi,&len);
    printf("Now input your string");
    scanf("%[^\n]s",initial_String);
    substring(initial_String, sub_String, posi, len);

    printf ("%s",sub_String);

return 0;
}