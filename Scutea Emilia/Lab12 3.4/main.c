#include <stdio.h>
#include <stdlib.h>

void reverse(int n,int ct)
{
    char *p=(char*)malloc(sizeof(char*)*100);
    if(ct<n)
    {
        printf("Please input a new word:\n");
        //getchar();
        scanf("%s",p);
        reverse(n,ct+1);
        printf("%s ",p);
    }
}
int main()
{
    int n;
    printf("Please input the number of words:\nn=");
    scanf("%d",&n);
    reverse(n,0);


    return 0;
}
