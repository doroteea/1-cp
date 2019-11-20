#include <stdio.h>
#include <stdlib.h>

int main()
{
        float x,min,max;
        int i,n,posmin,posmax;
        printf("n=");
        scanf("%d",&n);
        scanf("%f",&x);
        min=x;
        max=x;
        posmin=1;
        posmax=1;
        for(i=2;i<=n;i++){
                scanf("%f",&x);
                if(x>max){
                    max=x;
                    posmax=i;
                }
                if(x<min){
                    min=x;
                    posmin=i;
                }
        }
        printf("\nThe maximum is %f and its position %d",max,posmax);
        printf("\nThe minimum is %f and its position %d",min,posmin);

return 0;
}
