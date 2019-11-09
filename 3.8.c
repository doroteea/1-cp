#include <stdlib.h>

#include <stdio.h>

#include <string.h>

int main() {
    struct book {
        char author[26];
        char title[36];
        int year;
    }
    aux, list[55];
    int n;
    printf("n = ");
    scanf("%d", & n);
    int i, j;
    for (i = 0; i < n; i++) {
        fgets(list[i].author, 25, stdin);
        getchar();
        fgets(list[i].title, 35, stdin);
        getchar();
        scanf("%d", & list[i].year);
        fflush(stdin);
    }

    printf("the authors in alphabetic order are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", list[i].author);
    }
    return 0;
}
