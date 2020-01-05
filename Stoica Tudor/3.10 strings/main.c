///  312 412.412.41 55.5555 819?ppp !!232aa??;::
/// 241. 12312.. 11.1 22.000
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
const char delim[50]=" ?;:,!\/abcdefghijklmnopqrtuvwxyz";
const char space[1]=" ";
char g='a';
const char nrWithout0[12]="123456789";
int cnt,sum;
char mat[100][80];
int v[100];

void convert(char a[])
{
    unsigned len=strlen(a);
    char aux[100];
    strcpy(aux,a);
    char t[20];
    // printf("\n %s",strchr(aux,'.'));
    strcpy(t,strchr(aux,'.'));

    // printf("\n %s",t);

    if(t!=NULL) /// e cu virgula
    {
        if(t[1]==NULL) /// ex 214198.
        {
            // printf("\n %s",t);
            a[len-1]=NULL;
            aux[len-1]=NULL;
            len=len-1;
            // printf("\n %s",a);

            for(int i=0; i<len; i++)
            {
                v[i]=aux[i]-48;
            }
        }

        else
        {
            unsigned ll=strlen(t);
            bool exitt=false;

            for(unsigned i=0; i<ll; i++)
            {
                if(strchr(nrWithout0,t[i]))
                {
                    exitt=true;
                    break;
                }
            }

            if(exitt==false) /// 21312.0000000 -> 21312
            {
//                printf("\n%d",t[0]);
//                aux[t[0]]=NULL;
//                printf("\n%s",aux);
            }
            else
            {
                strcpy(t,t+1);
                printf("\n %s",t);
            }
        }


    }

    else /// fara virgula
    {
        unsigned size2=strlen(aux);

        for(int i=0; i<size2; i++)
        {
            v[i]=aux[i]-48;
        }
        /////////////////////////////////////////////
        if(size1>size2)
        {
            for(int i=size2; i>=1; i--)
            {
                v2[i+dif]=v2[i];
                v2[i]=0;
            }
        }

        else if(size1<size2)
        {
            for(int i=size1; i>=1; i--)
            {
                v1[i+dif]=v1[i];
                v1[i]=0;
            }
        }

        for(int i=maxx; i>=0; i--)
        {
            int sum=v1[i]+v2[i]+carry;

            if(sum>=10)
            {
                carry=1;
                rez[++size]=sum%10;
            }

            else
            {
                carry=0;
                rez[++size]=sum;
            }
        }

        reverseIntVec(rez,size,1);
    }
////////////////////////////////////////////////////////
}



int main()
{
    char* s=(char*) malloc(105);
    gets(s);
    // printf("%s",s);

    char* token = strtok(s, space);

    while (token != NULL)
    {
        bool exit=false;
        int dotCnt=0;
        unsigned len=strlen(token);

        for(unsigned i=0; i<len; i++)
        {
            if(!strchr(delim,token[i]))
            {
                if(token[i]=='.')
                {
                    dotCnt++;
                }
                continue;
            }
            else
            {
                exit=true;
                break;
            }
        }

        if(exit==false && dotCnt<=1)
        {
            strcpy(mat[cnt],token);
            cnt++;
        }

        /// printf("%s\n",token);
        token = strtok(NULL, space);
    }

//    for(int i=0; i<cnt; i++)
//    {
//        printf("%s\n",mat[i]);
//    }

    for(int i=0; i<cnt; i++)
    {
        // add(sum,convert(mat[i]));
        // printf("%s\n",mat[i]);

        convert(mat[i]);

        for(int j=0;j<100;j++)
        {
            v[j]=0;
        } /// reformare
    }
    printf(sum);

    return 0;
}
