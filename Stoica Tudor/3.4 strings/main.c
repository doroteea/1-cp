#include <stdio.h>
#include <stdlib.h>

char *deleteSubString(char* String, int begIndex, int len)
{
    int size=strlen(String);

    for(int i=begIndex+len; i<size; i++) /// a b c d e f g h i j k l m o p
    {
        String[i-len]=String[i];
    }
    return String;
}

int main()
{
    char a[]="abcdefghijklmop";
    printf("%s",deleteSubString(a,3,3));

    return 0;
}
