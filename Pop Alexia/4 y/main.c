#include <stdio.h>
#include <stdlib.h>

int main()
{ int an,x;
scanf("%d",&an);
 if(an%4!=0)
 x=1;
 else if (an%100!=0)
    x=0;
 else if (an%400!=0)
    x=1;
 else x=0;
 if (x==1)
 printf(" anul %d este obisnuit \n",an);
 else
    printf("anul %d este bisect",an);


    return 0;
}
