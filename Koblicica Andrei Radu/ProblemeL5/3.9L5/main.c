#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//nu stiu de ce nu imi mergea bine cu functie, am pus totul in main si asa e ok
int main()
{
    int Arabic;
    char *Roman=(char*)malloc(sizeof(char)*100);
    int *v=(int*)malloc(sizeof(int)*4);
    int Weight=1,i=0;
    strcpy(Roman," ");
    scanf("%d",&Arabic);
    while(Arabic)
    {
        v[i]=(Arabic%10)*Weight;
        Arabic/=10;
        Weight*=10;
        i++;
    }
    //in v am descompus numarul in bucati
    for(int j=i-1; j>=0; j--)
    {
        while(v[j])
        {
            if(v[j]<4)
            {
                while(v[j])
                {
                    strcat(Roman,"I");
                    v[j]--;
                }
            }
            if(v[j]==4)
            {
                strcat(Roman,"IV");
                v[j]=0;
            }
            if(v[j]>=5&&v[j]<9)
            {
                strcat(Roman,"V");
                v[j]-=5;
            }
            if(v[j]==9)
            {
                strcat(Roman,"IX");
                v[j]=0;
            }
            if(v[j]>=10&&v[j]<=30)
            {
                while(v[j])
                {
                    strcat(Roman,"X");
                    v[j]-=10;
                }
            }
            if(v[j]==40)
            {
                strcat(Roman,"XL");
                v[j]=0;
            }
            if(v[j]>=50&&v[j]<=80)
            {
                strcat(Roman,"L");
                v[j]-=50;
            }
            if(v[j]==90)
            {
                strcat(Roman,"XC");
                v[j]=0;
            }
            if(v[j]>=100&&v[j]<=300)
            {
                while(v[j])
                {
                    strcat(Roman,"C");
                    v[j]-=100;
                }
            }
            if(v[j]==400)
            {
                strcat(Roman,"CD");
                v[j]=0;
            }
            if(v[j]>=500&&v[j]<=800)
            {
                strcat(Roman,"D");
                v[j]-=500;
            }
            if(v[j]==900)
            {
                strcat(Roman,"CM");
                v[j]=0;
            }
            if(v[j]>=1000)
            {
                while(v[j])
                {
                    strcat(Roman,"M");
                    v[j]-=1000;
                }
            }
        }
    }
    strcpy(Roman,Roman+1);
    printf("%s",Roman);
}
