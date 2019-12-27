#include "rws.h"
int main()
{
    FILE *f=fopen("movies.txt","r");
    int nrOfDistActors=0,nrOfDistMovies=0;
    char *nameOfActor=(char*)malloc(sizeof(char)*30);
    movie *movies=(movie*)malloc(sizeof(movie)*30);
    actor *actors=(actor*)malloc(sizeof(actor)*300);
    rasFILE(f,movies,actors,&nrOfDistActors,&nrOfDistMovies);
    printMoviesandActors(movies,actors,nrOfDistMovies,nrOfDistActors);
    detFriendsOftheActors(movies,actors,nrOfDistMovies,nrOfDistActors);
    printf("Give the name of the actor:");
    gets(nameOfActor);
    if(PosofActor(nameOfActor,actors,nrOfDistActors)!=-1)
    {showOnesAllFriends(actors[PosofActor(nameOfActor,actors,nrOfDistActors)]);}
    else {printf("This actor doesn't exist in the database.\n");}
    return 0;
}
