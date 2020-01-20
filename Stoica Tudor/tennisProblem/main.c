#include "functions.h"

char **initMatches(char **s)
{
    s=(char**) malloc(sizeof(char*)*MAX_NR_MATCHES);

    for(int i=0; i<MAX_NR_MATCHES; i++)
    {
        s[i]=(char*) malloc(MAX_LENGTH_MATCH);
    }
    return s;
}

char **readInput(char **s,FILE *f)
{
    while(fgets(s[nrMatches],MAX_LENGTH_MATCH,f)!=NULL)
    {
        nrMatches++;
    }
    return s;
}

void solveTask(char **s,FILE *f)
{
    for(int i=0; i<nrMatches; i++)
    {
        processMatch(s[i],f);
        fprintf(f,"\n\n");
    }
}

void processMatch(char *s,FILE *f)
{
    int matchLen=strlen(s);
    int pointA=0,pointB=0;
    int gameA=0,gameB=0;
    int setA=0,setB=0;
    int currentSet=0;

    int *A=(int*) malloc(sizeof(int)*MAX_NR_GAMES_PLAYER);
    int *B=(int*) malloc(sizeof(int)*MAX_NR_GAMES_PLAYER);

    for(int i=0; i<matchLen; i++)
    {
        if(s[i]=='A')
        {
            pointA++;

            if((pointA>=4 && pointB<=2)||(pointA>=3 && pointB>=3 && pointA-pointB>=2)) ///A wins game
            {
                pointA=0;
                pointB=0;
                gameA++;
                if((gameA>=6 && gameB<=4)||(gameA>=7 && gameB>=5 && gameA-gameB>=2)) ///A wins set
                {
                    A[currentSet]=gameA;
                    B[currentSet]=gameB;
                    fprintf(f,"Set Score: A-%d B-%d\n",A[currentSet],B[currentSet]);

                    gameA=0;
                    gameB=0;
                    setA++;
                    currentSet++;
                    if(setA==2) ///A wins match
                    {
                        fprintf(f,"Match Over, A wins.");
                        setA=0;
                        setB=0;
                        return;
                    }
                }
            }
        }

        else if(s[i]=='B')
        {
            pointB++;

            if((pointB>=4 && pointA<=2)||(pointB>=3 && pointA>=3 && pointB-pointA>=2)) ///B wins game
            {
                pointB=0;
                pointA=0;
                gameB++;
                if((gameB>=6 && gameA<=4)||(gameB>=7 && gameA>=5 && gameB-gameA>=2)) ///B wins set
                {
                    A[currentSet]=gameA;
                    B[currentSet]=gameB;
                    fprintf(f,"Set Score: A-%d B-%d\n",A[currentSet],B[currentSet]);

                    gameB=0;
                    gameA=0;
                    setB++;
                    currentSet++;
                    if(setB==2) ///B wins match
                    {
                        fprintf(f,"Match Over, B wins.");
                        setA=0;
                        setB=0;
                        return;
                    }
                }
            }
        }
    }

    /// if match did not end

    for(int i=0; i<currentSet; i++)
    {
        fprintf(f,"Set Score: A-%d B-%d\n",A[currentSet],B[currentSet]);
    }
    fprintf(f,"Match incomplete.\n");
}

int main()
{
    FILE *i=fopen("input.txt","r");
    FILE *o=fopen("output.txt","w");

    char **match;
    match=initMatches(match);
    match=readInput(match,i);

    solveTask(match,o);

    return 0;
}
