#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,c;
    printf("n=");
    scanf("%d",&n);
    c=0;
    printf("\nPrime numbers until %d:",n);
    for(i=2;i<=n;i++){
        for(j=1;j<=i;j++){
            if(i%j==0){
                c++;
            }
        }
        if (c==2){
            printf(" %d ",i);
        }
        c=0;
    }

return 0;
}
