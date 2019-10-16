#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n,d;
    scanf("%n",&n);
    if(n==0||n==1){
        printf("There are no prime numbers <=n \n");
    }
    for(int i=2;i<=n/2;i++){
        bool isPrime=true;
        for(d=2;d*d<i&&isPrime;d++){
            if(i%d==0){
                isPrime=false;
            }
        }
        if(isPrime){
            printf("%d, ",i);
        }
    }
    return 0;
}
