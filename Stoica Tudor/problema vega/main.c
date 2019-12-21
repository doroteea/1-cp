#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


char filename[]="in.txt";
int nrOfFiles;
char file[105][25];

char *readFile(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;

    if (file == NULL)
        return NULL; //could not open file

    code = malloc(1005);

    while ((c = fgetc(file)) != EOF)
    {
        code[n++] = (char) c;
    }

    // don't forget to terminate with the null character
    code[n] = '\0';

    return code;
}
bool firstApparitionisCode(char* pnt,int index)
{
    char * aux=(char*) malloc(1005);
    strcpy(aux,pnt);

    for(int ii=index; aux[ii]!='\n'; ii++)
    {
        // printf("%c",aux[i]);
        if(aux[ii]!='/' && aux[ii+1]!='/' && aux[ii]!=' ') /// ai gasit cod
        {
            // printf("\n \n");
            return true;
        }

        if(aux[ii]=='/' && aux[ii+1]=='/') /// e comentariu
        {
            return false;
        }

        if(aux[ii]==' ') /// e doar spatiu gol
        {
            ii++;
        }
    }

    return false;
}

bool foundStartOfBigComment(char* pnt,int index)
{
    if(pnt[index]=='/' && pnt[index+1]=='*')
    {
        return true;
    }
    return false;
}

bool foundEndOfBigComment(char* pnt,int index)
{
    if(pnt[index]=='*' && pnt[index+1]=='/')
    {
        return true;
    }
    return false;
}

void querry1(char * in)
{
    char* input=(char*) malloc(1005);
    strcpy(input,in);
    int cnt=0;
    int stack=0;

    for(int i=0; input[i]!=NULL; i++)
    {

        if(stack==0)
        {
            if(firstApparitionisCode(input,i)==true)
            {
                cnt++;//printf("%d   ",i);
            }
        }

        while(input[i]!='\n')
        {
            //printf("%c%c \n",input[i],input[i+1]);


            if(foundStartOfBigComment(input,i)==true) /// /*
            {
                //printf("start %c%c \n",input[i],input[i+1]);
                stack++;
            }

            if(foundEndOfBigComment(input,i)==true)
            {
                //printf("end %c%c \n",input[i],input[i+1]);
                stack--;
            }
            i++;
        }
    }
    printf("%d \n",cnt);
}

void querry2(char *f)
{
    for(int i=0; i<nrOfFiles; i++)
    {
        querry1(f[i]);
    }
}

bool isFor(char * in, int i)
{
    if(in[i]=='f' && in[i+1]=='o' && in[i+2]=='r')
    {
        return true;
    }
    return false;
}

bool isDo(char * in,int i)
{
    if(in[i]=='d' && in[i+1]=='o')
    {
        return true;
    }
    return false;
}

bool isWhile(char * in,int i)
{
    if(in[i]=='w' && in[i+1]=='h' && in[i+2]=='i' && in[i+3]=='l' && in[i+4]=='e')
    {
        return true;
    }
    return false;
}

bool PunctSiVirgulaApareInainteDeAcolada(char* in,int index)
{
    char* aux=(char *) malloc(1005);
    strcpy(aux,in);
    int i=index;
    int psv=0;
    int acolada=0;

    while(true)
    {
        if(aux[i]==';')
        {
            return true;
        }

        if(aux[i]=='{')
        {
            return false;
        }
        i++;
    }
    return false;
}

void querry3(char * in)
{
    char* input=(char *) malloc(105);
    strcpy(input,in);

    int cnt=0;
    int start=0;
    int stop=0;
    int stack=0;

    for(int i=0; input[i]!=NULL; i++)
    {

        if(isWhile(input,i)==true)
        {
            if(PunctSiVirgulaApareInainteDeAcolada(input,i)==true) /// inseamna ca e while-ul de la doWhile
            {
                /// regleaza while(true);
            }

            else /// e while normal
            {
                cnt++;

                while(input[i]!='{')
                {
                    i++;
                }

                start=i;
                stack++;

                while(stack>0)
                {
                    i++;

                    if(input[i]=='{')
                    {
                        stack++;
                    }

                    if(input[i]=='}')
                    {
                        stack--;
                    }
                }

                stop=i;

                for(int ii=start; ii<=stop; ii++)
                {
                    printf("%c",input[ii]);
                }
                printf("\n \n \n \n \n ");
                i=start;
            }
        }

        if(isFor(input,i)==true || isDo(input,i)==true)
        {
            cnt++;

            while(input[i]!='{')
            {
                i++;
            }

            start=i;
            stack++;

            while(stack>0)
            {
                i++;

                if(input[i]=='{')
                {
                    stack++;
                }

                if(input[i]=='}')
                {
                    stack--;
                }
            }

            stop=i;

            for(int ii=start; ii<=stop; ii++)
            {
                printf("%c",input[ii]);
            }
            printf("\n \n \n \n \n ");
            i=start;
        }
    }

    printf("%d",cnt);
}

bool psvInainteDeParanteza(char * p, int index);

bool isTestFunction(char * in, int index)
{
    char* aux=(char *) malloc(105);
    strcpy(aux,in);

    int comas=0;
    bool isFunction=false;

    if(aux[index]=='t' && aux[index+1]=='e' && aux[index+2]=='s' && aux[index+3]=='t') /// scrie test
    {
        if(psvInainteDeParanteza(aux,index+4)==true)
        {
            /// e variabila
            return false;
        }
        else /// e functie (are paranteze)
        {
            // isFunction=true;
            int ii=index+4;

            while(aux[ii]!=')') /// vad cate virgule exista intre parantezele alea
            {
                if(aux[ii]==',')
                {
                    comas++;
                }
                ii++;
            }
            if (comas==0)
            {
                printf("0 parameters \n");
            }
            else
            {
                printf("%d parameters \n",comas+1);
            }
            return true;
        }
    }
    return false;
}

bool psvInainteDeParanteza(char * p, int index)
{
    char * pp=(char*) malloc(1005);
    strcpy(pp,p);

    int i=index;

    while(true)
    {
        if(pp[i]==';')
        {
            return true;
        }

        if(pp[i]=='(')
        {
            return false;
        }
        i++;
    }
    return false;
}
void querry4(char* in)
{
    char* input=(char *) malloc(105);
    strcpy(input,in);

    // bool doMethodAgain=true;

    for(int i=0; input[i]!=NULL; i++)
    {
        if(isTestFunction(input,i)==true)
        {
            return;
        }
//        daca iti da doar antetul functiei dai semnal ca ai mai afisat o data si sa nu afiseze de 2 ori ------bifat
//        sa dai return daca ai afisat-----------bifat
    }
    printf("error, function test does not exist");
}
int main()
{
    char* input=(char*) malloc(1005);
    input=readFile(filename);

    // querry1(input);
//    querry2(file);
     querry3(input); /// merge, mai putin daca nu pui acolade
    // querry4(input);

    return 0;
}
