#include <stdio.h>
#include <stdlib.h>
void HanoiAlgorithm( int n,char source, char destination, char aux)
{
    {
        if(n==1)
        {
            printf("%c -> %c\n",source,destination);
        }
        else
        {
            HanoiAlgorithm(n-1,source,aux,destination);
            printf("%c -> %c\n",source,destination);
            HanoiAlgorithm(n-1,aux,destination,source);
        }
    }
}
int main()
{
    int n;
    char a='A',b='B',c='C';
    printf("Write the nr of disks= ");
    scanf("%d",&n);
    HanoiAlgorithm(n,a,c,b);
    return 0;
}
