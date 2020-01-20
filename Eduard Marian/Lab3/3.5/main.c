#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    bool maxPerfSquare=true;
    for(i=1;i<=n&&maxPerfSquare;i++){
        if(i*i>n){
            maxPerfSquare=false;
        }
    }
    i-=2;
    printf("The greatest perfect square that is less than or equal to n is %d \n",i*i);
    while(!maxPerfSquare){
        bool prime=true;
        for(int d=2;d*d<=n&&prime;d++)
            if(n%d==0){
                prime=false;
        }
        if(prime){
            maxPerfSquare=true;
        }
        else n++;
    }
    printf("The least prime number that is greater than or equal to n is %d \n",n);
    return 0;
}
