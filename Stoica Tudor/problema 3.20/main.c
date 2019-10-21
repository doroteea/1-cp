#include <stdio.h>
#include <string.h>
char prop[300],*token;
const char delim[20]=" .?;:,!";
int cnt;

int main() {

    scanf("%s", prop);
    char* token = strtok(prop, delim);

    while (token != NULL) {
        printf("%s\n",token);
        cnt++;
        token = strtok(NULL, delim);
    }
    printf("%d", cnt);
/// for Ana are mere it only couts Ana
/// for any other Ana.are.mere it couts Ana are mere
    return 0;
}
