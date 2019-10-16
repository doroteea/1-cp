#include <stdio.h>
#include <stdlib.h>

int main()
{int i,length,min,max,a[length];
printf("Enter length\n");
scanf("%d",&length);
printf("enter numbers\n");
for(i=0;i<length;i++)
{scanf("%d",&a[i]);

}
max=a[0];
min=a[0];
for(i=1;i<length;i++)
{
    if(a[i]>max)
    {
        max=a[i];
    }
    if(a[i]<min)
    {
        min=a[i];
    }
}
printf("Maximum element=%d\n",max);
printf("Minimum element=%d\n",min);

    return 0;
}
