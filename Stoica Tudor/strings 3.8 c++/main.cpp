#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("3.8.in");
ofstream fout("3.8.out");

char author[105][25],title[105][25],publicationYear[105][25],s[25];
int index=0,year[105];

void read()
{
    int i=-1;

    while(fin.get(s,25))
    {
        i++;

        if(i==0)
        {
            strcpy(author[index],s);
        }

        if(i==1)
        {
            strcpy(title[index],s);
        }

        if(i==2)
        {
            strcpy(publicationYear[index],s);
            i=-1;
            index++;
        }
        fin.get();
    }
}

void sortAuthors()
{
    for(int i=0; i<index-1; i++)
    {
        for(int j=i+1; j<index; j++)
        {
            if(author[i][0]>author[j][0])
            {
                char aux[25];

                strcpy(aux,author[i]);
                strcpy(author[i],author[j]);
                strcpy(author[j],aux);

                strcpy(aux,title[i]);
                strcpy(title[i],title[j]);
                strcpy(title[j],aux);

                strcpy(aux,publicationYear[i]);
                strcpy(publicationYear[i],publicationYear[j]);
                strcpy(publicationYear[j],aux);

            }
        }
    }
}

void querry1()
{
    fout<<"querry 1:"<<"\n"<<"\n";
    sortAuthors();

    for(int i=0; i<index; i++)
    {
        fout<<author[i]<<endl;
    }

    fout<<"\n";
}
void charToIntYear();

void querry2()
{
    fout<<"querry 2:"<<"\n"<<"\n";
    charToIntYear();

    for(int i=0; i<index-1; i++)
    {
        for(int j=i+1; j<index; j++)
        {
            if(year[i]>year[j])
            {
                char aux[25];

                strcpy(aux,author[i]);
                strcpy(author[i],author[j]);
                strcpy(author[j],aux);

                strcpy(aux,title[i]);
                strcpy(title[i],title[j]);
                strcpy(title[j],aux);

                strcpy(aux,publicationYear[i]);
                strcpy(publicationYear[i],publicationYear[j]);
                strcpy(publicationYear[j],aux);
            }
        }
    }

            for(int i=0;i<index;i++)
        {
            fout<<author[i]<<"\n"<<title[i]<<"\n"<<"\n";
        }
}

void charToIntYear()
{
    for(int i=0; i<index; i++)
    {
        int len=strlen(publicationYear[i]);
        int p=1;

        for(int j=len-1; j>=0; j--)
        {
            year[i]=year[i]+p*((int) publicationYear[i][j]-48);
            p=p*10;
        }
    }
}

int main()
{

    read();
    querry1();
    querry2();

    return 0;
}
