#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    FILE * f=fopen("test2.txt","r");
    fscanf(f,"%d\n",&n);
    printf("%d",n);

    return 0;
}
