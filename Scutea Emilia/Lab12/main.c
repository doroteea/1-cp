#include <stdio.h>
#include <stdlib.h>

void reverse(void)
{
    char c;
    scanf("%c", &c);
    if (c!=' ')
    {
        printf("%c", c);
        reverse();
    }
    printf("%c", c);
}

int main(void)
{
    int n, i;
    printf("The number of the words=");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        reverse();
        printf("   ");
    }
    printf("\nEnd of the program.\n");
    return 0;
}


