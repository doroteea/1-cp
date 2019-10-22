#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,ps,c,j,b;
i=1;
ps=1;
printf("Introduce the number:\n");
scanf("%d",&n);
while (i*i<=n){
    ps=i*i;
    i++;
}
printf("The greatest perfect square less or equal to %d is %d\n",n,ps);
i=n;
b=0;
c=0;
while(b==0){
    for(j=1;j<=i;j++){
            if(i%j==0){
                c++;
            }
        }
        if (c==2){
            printf("The least prime number greater or equal to %d is %d \n",n,i);
            b=1;
        }
        else{
            i++;
        }
        c=0;
}

return 0;
}
