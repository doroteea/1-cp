#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100],inser[100],aux[100];
    int poz;
    scanf("%s %s %d",s,inser,&poz);
    strcpy(aux,s+poz);
    strcpy(s+poz,inser);
    strcat(s,aux);
    printf("%s\n",s);
    return 0;
}
