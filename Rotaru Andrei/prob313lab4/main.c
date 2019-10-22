#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,b;
    printf("Introduce the size of the vector: ");
    scanf("%d",&n);
    float v[n],x;
    for(i=1;i<=n;i++){
        scanf("%f",&v[i]);
    }
    i=1;
    printf("\nx= ");
    scanf("%f",&x);
    b=0;
    while(i<=n&b==0){
        if(v[i]==x){
            b=1;
        }
        else{
            i++;
        }
    }
    if(b==1){
        printf("%f is in the sequence and its position is %d \n",x,i);
    }
    else{
        printf("%f is not in the sequence \n",x);
    }
return 0;
}
