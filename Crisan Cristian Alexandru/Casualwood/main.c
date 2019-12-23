#include "rws.h"
int main()
{
    FILE *f=fopen("movies.txt","r");
    int nrOfDistActors=0,nrOfDistMovies=0;
    movie *movies=(movie*)malloc(sizeof(movie)*30);
    actor *actors=(actor*)malloc(sizeof(actor)*300);
    rasFILE(f,movies,actors,&nrOfDistActors,&nrOfDistMovies);
    printf("da");
    printMoviesandActors(movies,actors,nrOfDistMovies,nrOfDistActors);


    return 0;
}
