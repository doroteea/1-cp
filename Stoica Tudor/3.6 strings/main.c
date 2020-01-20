#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseCharVec(char *vec, int len)
{
    for(int i=0; i<=len/2; i++) /// 5 9 8 1 7 5 9
    {
        char aux=vec[i];
        vec[i]=vec[len-i];
        vec[len-i]=aux;
    }
}

char *intToString(int nr)
{
    char* String=(char*) malloc(105);
    int len=0;

    while(nr!=0)
    {
        char c=nr%10+'0';
        String[len++]=c;
        nr=nr/10;
    }
    String[len]=NULL;
    reverseCharVec(String,len-1);

    return String;
}

int stringToInt(char* String)
{
    int len=strlen(String);
    int p=1,nr=0;

    for(int i=len-1; i>=0; i--)
    {
        nr=nr+p*String[i];
        p=p*10;
    }
    return nr;
}

int main()
{
    return 0;
}
