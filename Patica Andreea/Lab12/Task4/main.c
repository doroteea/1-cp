#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse (char **s, int n)
{
    if (n==0)
    {
        return;
    }
    printf("%s\n", s[n-1]);
    reverse(s, n-1);
}

int main()
{
    int n;
    scanf("%d", &n);
//    getchar();

    char **s = (char**)malloc(sizeof(char*)*n);

    for (int i=0; i<n; i++)
    {
        s[i]=(char*)malloc(sizeof(char)*100);
        scanf("%s", s[i]);
    }
    reverse(s, n);

    return 0;
}
