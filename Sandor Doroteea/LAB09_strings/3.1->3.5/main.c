//
//  main.c
//  LAB8+3.1-3.5
//
//  Created by Sandor Doroteea on 11/8/19.
//  Copyright © 2019 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>
#include <string.h>
//3.1  Asta o dat bine cand l-am verificat

void string_functions( char *s1 , char *s2){

    // strlen
    int n1=strlen(s1) , n2=strlen(s2);
    printf("Lungimea sirului s1=%d\n",n1);
    printf("Lungimea sirului s2=%d\n",n2);
    // strcpy & strncpy
    char s3[100];
    strcpy(s3,s1);
    printf("\nAm copiat intr-un sir s3 primul sir si vom afisa sirul s3 modificat: %s",s3);
    char s4[]="mangooo";
    strncpy(s2,s4,5);
    s2[5]='\0';
    printf("\nAm copiat in al doilea sir  primele 5 cifre dintr-un sir s4 si vom afisa : %s",s2);

    // strcat & strncat
    char s5[]="sunny_day";
    strcat(s1,s5);
    printf("\nAm concatenat primului sir un sir s5 si se va afisa : %s",s1);
    strncat(s1,s5,3);
    printf("\nAm concatenat primului sir inca 3 caractere din acelasi sir s5 si vom afisa : %s",s1);

    // strcmp & strncmp
    strcpy(s1,"WATER");
    printf("\nPrimul sir devine: %s",s1);
    strcpy(s2,"WATERFALL");
    printf("\nAl doilea sir devine: %s",s2);
    int x = strcmp(s1,s2);
    int y = strncmp(s1,s2,5);
    printf("\n Comparam s1 cu s2 si obtinem: %d",x);
    printf("\n Comparam s1 cu primele 5 caractere din s2 si obtinem: %d",y);
}

// 3.2 Nu stiu de ce nu merge...sigur am gresit cv la pointers sau poate algoritmul la functie idk :)

void substring(int i,int n,char *s1)
{
    char s[]="Dogs_are_cute";
    strcpy(s1,s+i);
    *(s1+n)='\0';
}

// 3.3 Nici asta nu vrea sa mearga:))

void insert_string(int i , char s1 , char s2){
    char aux[]="";
    strcpy(aux,s1+i);
    strcpy(s1+i,s2);
    strcat(s1,aux);
}
 // 3.4 ctrlc+ctrlv comm anterior

 void delete_substring(int i,int n,char *s){
    char aux[]="";
    strcpy(aux,s+i+n);
    strcpy(s+i,aux);
}

 // 3.5 I really don't know what's wrong

 void verify_substring(int &i ,char s[], char gstring[]){
     char *s1;
     strcpy(s1,strstr(s,gstring));
     i=strlen(s)-strlen(s1);
     strcpy(s,s1);

 }

int main(int argc, const char * argv[]) {
   char string1[100], string2[100];
     //3.1
    scanf("%s",string1);
    scanf("%s",string2);
    string_functions(&string1, &string2);

    //3.2
     int i,n;
     char *string4;
    scanf("%d",&i);
    scanf("%d",&n);
    substring(i,n,&string4);
    printf("\nEx. 3.2\n: %s",string4);

     //3.3
    char string5[]="abracadabra", string6[]="alladin";
    int a;
    scanf("%d",&a);
    insert_string(a,string5,string6);
    printf("\nEx. 3.3:\n%s",string5);
    return 0;

    // 3.4
    char string7[100];
    int i,n;
    scanf("%s",string7);
    delete_substring(i,n,&string7);
    printf("\nEx 3.4:\n%s",string7);

    // 3.5
    char string8[]="abracadabra", string9[]="cada";
    int i;
    scanf("%d",&i);
    verify_substring(i,string8,string9);
    printf("\nEx. 3.5:\N%s\nPosition:%d",string8,i);
}
