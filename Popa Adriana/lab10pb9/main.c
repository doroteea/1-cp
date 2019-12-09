#include "lorry.h"

int main()
{
    int m;
    printf("m=");
    scanf("%d",&m);
    lorry *l=readLorry(m);
    int maxLoad;
    printf("give max load");
    scanf("%d",&maxLoad);
    maxValue(m,l,maxLoad);
    return 0;
}
