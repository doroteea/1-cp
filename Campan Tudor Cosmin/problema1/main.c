#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{char s[100],subs[100];
int poz,lungime;
scanf("%s %d %d",s,&poz,&lungime);
    strncpy(subs,s+poz,lungime);
    printf("%s",subs);
    return 0;
}
