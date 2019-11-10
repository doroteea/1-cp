#include <stdio.h>
#include <stdlib.h>

int main()
{ int i,length,min,max,sequence[length];
printf("Enter length\n");
scanf("%d",&length);
printf("Enter numbers\n");
for(i=0;i<length;i++)
{
   scanf("%d",&sequence[i]);
}
 min=sequence[0];
 max=sequence[0];
 for(i=1;i<=length;i++)
 {
     if(sequence[i]>max)
     {
         max=sequence[i];
     }
     if(sequence[i]<min)
     {
         min=sequence[i];
     }
 }
 printf("Maximum=%d\n",max);
 printf("Minimum=%d\n",min);
    return 0;
}
