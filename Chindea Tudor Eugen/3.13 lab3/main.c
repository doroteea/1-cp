#include <stdio.h>
#include <stdlib.h>



int main()
{
    int sir[100],n,x,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&sir[i]);
    }
    scanf("%d",&x);
    for(i=0; x>sir[i]&&i<n; i++);
    if(x==sir[i])
    {
        printf("Numarul x= %d  apare pe pozitia i= %d",x,i);
    }
    return 0;
}
