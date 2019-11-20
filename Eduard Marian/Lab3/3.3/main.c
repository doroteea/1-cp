#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seq[100],n,maxVal,maxInd,minVal,minInd;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&seq[i]);
    }
    maxVal=seq[1];
    maxInd=1;
    minVal=seq[1];
    minInd=1;
    for(int i=1;i<=n;i++){
        if(seq[i]>maxVal){
            maxVal=seq[i];
            maxInd=i;
        }
        else if(seq[i]<minVal){
                minVal=seq[i];
                minInd=i;
             }
    }
    printf("Max Value=%d and its position is %d \n",maxVal,maxInd);
    printf("Min Value=%d and its position is %d \n",minVal,minInd);
    return 0;
}
