#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);

    if (!(x%4))
    {
        printf("The year is bissextile.\n");
    }
    else
    {
        printf("The year is not bossextile.\n");
    }
    return 0;
}
