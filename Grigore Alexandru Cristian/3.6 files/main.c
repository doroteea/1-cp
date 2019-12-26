#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *fname=(char*)malloc(sizeof(char)*100);
    printf("enter file name: ");
    gets(fname);
    int n;
    char *str=(char*)malloc(sizeof(char)*100);
    printf("Enter the nr of lines to be written:");
    scanf("%d",&n);
    FILE *f=fopen(fname,"w");
    for(int i=0;i<n+1;i++)
    {
        fgets(str,100,stdin);
        fprintf(f,"%d %s",i,str);

    }
    fclose(f);
    f=fopen(fname,"r");
    char line;
    while(!feof(f))
    {
        printf("%c",line);
        line=fgetc(f);
    }
    fclose(f);


    return 0;
}
