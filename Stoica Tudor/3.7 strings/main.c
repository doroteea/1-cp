#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int maxi=-1,index=0;
    int maxiANS=-1,indexANS=0;;
    const char delim[2]=" ";
    scanf("%d",&n);

    char **mat = (char **)malloc(sizeof(char *)*105);
    // int *sizeVec=(int *) malloc(4*105);
    int *sizeVec=(int *) malloc(sizeof(int *)*105);

    for(int i=0; i<105; i++)
    {
        mat[i]=(char *) malloc(sizeof(char)*105);
    }

    for(int i=0; i<n; i++)
    {
        scanf("%s",mat[i]);

        sizeVec[i]=strlen(mat[i]);
        if(sizeVec[i]>maxi)
        {
            maxi=sizeVec[i];
            index=i;
        }

        char* aux=(char *) malloc(sizeof(char)*105);
        strcpy(aux,mat[i]);
        char* token = strtok(aux, delim);

        while(token!=NULL)
        {
            int sz=strlen(token);

            if(sz>maxiANS)
            {
                maxiANS=sz;
                indexANS=i;
            }

            token=strtok(NULL,delim);
        }
    }

    printf("%s \n %s",mat[index],mat[indexANS]);

    return 0;
}
