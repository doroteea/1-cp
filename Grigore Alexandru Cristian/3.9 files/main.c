#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
   FILE *f=fopen("realnumbers.txt","r");
   FILE *g=fopen("realnumbers2.txt","r");
   FILE *h=fopen("real.txt","w");
   char ch;
   while((ch=fgetc(f))!=EOF)
   {
    fputc(ch,h);
   }
   while((ch=fgetc(g))!=EOF)
   {
       fputc(ch,h);
   }
   fclose(f);
   fclose(g);
   fclose(h);
    return 0;
}
