///Read from the standard inputa natural number,n. Checkif this number is palindrome.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, pal = 0, p = 1, aux;
    while(scanf("%d", &n) && n){
        aux = n;

        while(aux != 0){
            pal = pal * 10 + aux % 10;
            aux/= 10;
        }

        if(pal == n)
            printf("Numarul %d este palindrom", n);
        else
            printf("Numarul %d nu este palindrom", n);
            pal = 0;
    }
    return 0;
}
