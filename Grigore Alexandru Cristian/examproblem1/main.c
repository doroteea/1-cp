#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compareFiles(FILE *f1,FILE *f2)
{
    char ch1=getc(f1);
    char ch2=getc(f2);
    int error=0;
    int pos=0;
    int line=1;
     while (ch1 != EOF && ch2 != EOF)
    {
        pos++;
         if (ch1 == '\n' && ch2 == '\n')
        {
            line++;
            pos = 0;
        }
        if (ch1 != ch2)
        {
            error++;
            printf("Line Number : %d \tError"
               " Position : %d \n", line, pos);
        }
         ch1 = getc(f1);
         ch2 = getc(f2);
    }
    printf("Total Errors : %d\t", error);
}

int main()
{
    FILE *f1=fopen("user.txt","r");
    FILE *f2=fopen("user2.txt","r");
    compareFiles(f1,f2);
        fclose(f1);
        fclose(f2);

    return 0;
}
