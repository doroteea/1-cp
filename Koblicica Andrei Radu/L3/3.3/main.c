#include <stdio.h>
#include <stdlib.h>
float MaxValue,MinValue,var;
int n,i,MaxIndice=1,MinIndice=1;
int main()
{
    scanf("%d\n",&n);
    scanf("%f",&var);
    MaxValue=var;MinValue=var;
    for(i=1;i<n;i++)
    {
        scanf("%f",&var);
        if(var>MaxValue)
        {
            MaxValue=var;
            MaxIndice=i;
        }
        if(var<MinValue)
        {
            MinValue=var;
            MinIndice=i;
        }
    }
    printf("MaxValue is %f in position %d\n",MaxValue,MaxIndice);
    printf("MinValue is %f in position %d",MinValue,MinIndice);
    return 0;
}
