#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void extract(char *sir)
{
    int pos,length,sublength;
    printf("Give position and length \n");
    scanf("%d, %d",&pos,&length);
    char *sub=(char*)malloc(sizeof(char)*30);
    sublength=0;
    while(sublength<length)
    {
        sub[sublength]=sir[sublength+pos];
        sublength++;
    }
    sub[sublength]='\0';
    puts(sub);

}
void insertStrings(char *sir)
{
    int pos,lengths,lengthd,i,j;
    printf("Give position \n");
    scanf("%d",&pos);
    char *destination=(char*)malloc(sizeof(char)*60);
    printf("Give destination string \n");
    getchar();
    gets(destination);
    lengths=strlen(sir);
    lengthd=strlen(destination);
    for(i=lengthd;i>=pos;i--)
    {
        destination[i+lengths]=destination[i];
    }
    j=0;
    for(i=pos;i<pos+lengths;i++)
    {
        destination[i]=sir[j];
        j++;
    }
    destination[lengthd+lengths]='\0';
    puts(destination);

}
void deleteSubstring(char *sir)
{
    int pos,length;
    printf("Give position and length \n");
    scanf("%d, %d",&pos,&length);
    strcpy(sir+pos,sir+pos+length);
    puts(sir);
}
void verifySubstring(char *sir)
{
    int verify,i,j,length,lengthsub,pos;
    verify=0;
    char *sub=(char*)malloc(sizeof(char)*60);
    printf("Give substring \n");
    gets(sub);
    length=strlen(sir);
    lengthsub=strlen(sub);
    for(i=0;i<length-lengthsub && verify==0;i++)
    {
        for(j=0;j<lengthsub;j++)
        {
            if(sir[i+j]!=sub[j])
            {
                break;
            }
        }
        if(j==lengthsub)
        {
            pos=i;
            verify=1;
        }
    }
    if(verify==1)
    {
        printf("The given string is a substring,and the position is: %d",pos);
    }
    else{
        printf("The given string is not a substring");
    }
}
int main()
{
    char *sir=(char*)malloc(sizeof(char)*30);
    gets(sir);
    //extract(sir);
    //deleteSubstring(sir);
    //verifySubstring(sir);
    insertStrings(sir);
    return 0;
}
