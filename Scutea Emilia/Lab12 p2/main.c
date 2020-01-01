#include <stdio.h>
#include <stdlib.h>

const int MAX_LENGTH=200;
int main()
{
    FILE *f;
    f=fopen("sentence.txt","rw+");
    int *vect=(int*)malloc(sizeof(int)*30);
    int n;
    fscanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char *sen=(char*)malloc(sizeof(char)*MAX_LENGTH);
        for(int j=0;j<strlen(sen);j++)
        {
            if(sen[j]>='a'&&sen[j]<='z')
            {
                vect[sen[j]-'0']++;
            }
        }
    }
    for(int i=0;i<30;i++)
    {
        printf("&d ",vect[i]);
    }
}
