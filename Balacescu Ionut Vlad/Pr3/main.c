#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main()
{

    int size,posmax,posmin;
    float realNumber,maxi=FLT_MIN,mini=FLT_MAX;
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        scanf("%f",&realNumber);
        if(realNumber>maxi){maxi=realNumber;posmax=i;}
        if(realNumber<mini){mini=realNumber,posmin=i;}
    }
    printf("Max si pozitia lui:%f %d\n",maxi, posmax);
    printf("Min si pozitia lui:%f %d\n",mini, posmin);
    return 0;
}
