#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    f=fopen("imput.txt","r");
    int sentence,nrofsent,i,j;
//    char *characters=(char*) malloc (sizeof(char)*27);
//    char c='a';
//    for(i=0; i<27; i++)
//    {
//        characters[i]=c;
//        c=c+('b'-'a');
//    }


    char ** sentances = (char**) malloc(sizeof(char*)*200);
    for(i=0; i<200; i++)
        sentances[i]=(char*) malloc(sizeof(char)*200);
    i=0;
    while (fgets(sentances[i], 500, f) != NULL)
    {
        i++;
        printf("%s\n",sentances[i]);
    }




    return 0;
}
