#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void alphabetical(char author[]){
    int i,j,n;
    char temp[10];

    for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
        if(strcmp(author[i],author[j])>0){
            strcpy(temp,author[i]);
            strcpy(author[i],author[j]);
            strcpy(author[j],temp);
        }
    }
}

printf("Authors in alphabetical order:\n");
for(i=0;i<n;i++)
{
    printf("\n%s",author[i]);
}
getch();
}
int main()
{
    char author[25];
    int i,j,n,year;
    printf("Enter number of books:\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter author %d:\n",i+1);
        gets(author[i]);
    }
alphabetical(author);

}
