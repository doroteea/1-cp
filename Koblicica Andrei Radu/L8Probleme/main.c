#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//3.2
void extractSubstring(char *sir, int position2, int nrOfCharacters)
{
    char *subsir=(char*)malloc(sizeof(char)*50);
    strncpy(subsir,sir+position2,nrOfCharacters);
    printf("resulting substring is %s\n",subsir);
}
//3.3
void insertString(char *sir, char *sir3, int position3)
{
    char *aux=(char*)malloc(sizeof(char)*50);
    strcpy(aux,sir3+position3);
    strcpy(sir3+position3,sir);
    strcat(sir3,aux);
    printf("resulting string is %s\n",sir3);
}
//3.4
void deleteSubstring(char *sir, int position4, int length4)
{
    char *sir4=(char*)malloc(sizeof(char)*50);
    strcpy(sir4,sir);
    strcpy(sir4+position4,sir4+position4+length4);
    printf("resulting string is %s\n",sir4);
}
//3.5
void isItSubstring(char *sir, char *sir5)
{
    char *p;
    if(strstr(sir,sir5)!=NULL)
    {
        p=strstr(sir,sir5);
        printf("%s is a substring of %s, beginning at position %d\n",sir5,sir,p-sir);
    }
    else printf("%s is not a substring of %s\n",sir5,sir);
}
//3.6  doesnt work because of the fractional parts, cant figure it out
//3.6.1
/*void realToString(float real)
{
    char *sir6=(char*)malloc(sizeof(char)*50);
    int integerPart=(int)real;
    float fractionalPart=real-(float)integerPart;
    int i=0;
    while(integerPart!=0)
    {
        sir6[i++]=(integerPart%10)+'0';
        integerPart/=10;
    }
    for(int i=0;i<=strlen(sir6)/2;i++)
    {
        int aux=sir6[i];
        sir6[i]=sir6[strlen(sir6)-i-1];
        sir6[strlen(sir6)-i-1]=aux;
    }
    strcat(sir6,".");
    while(fractionalPart>0)
    {
        fractionalPart*=10;
        sir6[i++]=(int)(fractionalPart)+'0';
        fractionalPart-=(int)fractionalPart;
    }
    printf("%s\n",sir6);
}
//3.6.2
void stringToReal(char *sir62)
{
    float real=0;int i=0;
    while(i<strlen(sir62)&&sir62[i]!='.')
    {
        real=real*10+(sir62[i]-'0');
        i++;
    }
    i++;int divider=10;
    while(i<strlen(sir62))
    {
        real+=((sir62[i]-'0')/divider);
        divider*=10;
    }
    printf("%f\n",real);
}*/
int main()
{
    char *sir=(char*)malloc(sizeof(char)*50);
    printf("sir=");scanf("%s",sir);
    //3.2
    int position2, nrOfCharacters;
    printf("3.2 position2=");scanf("%d",&position2);
    printf("nrOfCharacters=");scanf("%d",&nrOfCharacters);
    extractSubstring(sir,position2,nrOfCharacters);
    //3.3
    char *sir3=(char*)malloc(sizeof(char)*50);
    printf("3.3 destination string is %s\nsource string s3=",sir);scanf("%s",sir3);
    int position3;
    printf("position3=");scanf("%d",&position3);
    insertString(sir,sir3,position3);
    //3.4
    int position4,length4;
    printf("3.4 position4=");scanf("%d",&position4);
    printf("length4=");scanf("%d",&length4);
    deleteSubstring(sir,position4,length4);
    //3.5
    char *sir5=(char*)malloc(sizeof(char)*50);
    printf("3.5 sir5=");scanf("%s",sir5);
    isItSubstring(sir,sir5);
    //3.6.1
    /*float real;
    printf("3.6 sir5=");scanf("%f",&real);
    realToString(real);
    //3.6.2
    char *sir62=(char*)malloc(sizeof(char)*50);
    scanf("%s",sir62);
    stringToReal(sir62);*/
}
