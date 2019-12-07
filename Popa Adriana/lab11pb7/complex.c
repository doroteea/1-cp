#include "complex.h"

Complex* readComplex()
{
    Complex *c=(Complex*)(malloc(sizeof(Complex*)*100));
    FILE *f;
    f=fopen("complex.in","r");

    int i=0;
    char *p=(char*)(malloc(sizeof(char*)*100));
    char *strbuf=(char*)(malloc(sizeof(char*)*100));

    fgets(strbuf,100,f);
    n=atoi(strbuf);

    while(fgets(strbuf,100,f)!=NULL)
    {
        puts(strbuf);
        p=strtok(strbuf," ");
        c[i].real=atoi(p);
        p=strtok(NULL," ");
        c[i].imaginary=atoi(p);
        i++;
    }
    return c;
}

void printComplex(Complex *c,FILE *f)
{
    char *p=(char*)(malloc(sizeof(char*)*100));
    int i;
    fputs("The numbers are:\n",f);
    for(i=0; i<n; i++)
    {
        fputs("c",f);
        itoa(i+1,p,100);
        fputs(p,f);
        fputs(" = ",f);
        itoa(c[i].real,p,100);
        fputs(p,f);
        fputs(" + ",f);
        itoa(c[i].imaginary,p,100);
        fputs(p,f);
        fputs(" * i\n",f);
    }
}

int *calculateModulus(Complex *c)
{
    int i;
    int *mod=(int*)(malloc(sizeof(int*)*100));
    for(i=0; i<n; i++)
    {
        mod[i]=sqrt(c[i].real*c[i].real+c[i].imaginary*c[i].imaginary);
    }
    return mod;
}

void printModulus(int *mod,FILE *f)
{
    int i;
    char *p=(char*)(malloc(sizeof(char*)*100));
    for(i=0; i<n; i++)
    {
        fputs("\n|c",f);
        itoa(i+1,p,100);
        fputs(p,f);
        fputs("| = ",f);
        itoa(mod[i],p,100);
        fputs(p,f);
    }
}

int *calculateArgument(Complex *c)
{
    int i;
    int *arg=(int*)(malloc(sizeof(int*)*100));
    for(i=0; i<n; i++);
    {
        arg[i]=c[i].real/sqrt(c[i].real*c[i].real+c[i].imaginary*c[i].imaginary);
    }
    return arg;
}

void printArgument(int *arg,FILE *f)
{
    int i;
    char *p=(char*)(malloc(sizeof(char*)*100));
    fputs("\n",f);
    for(i=0; i<n; i++)
    {
        fputs("\narg( c",f);
        itoa(i+1,p,100);
        fputs(p,f);
        fputs(" ) = ",f);
        itoa(arg[i],p,100);
        fputs(p,f);
    }
}
