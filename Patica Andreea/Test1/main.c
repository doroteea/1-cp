#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x[11];
    for (int i=1; i<=10; i++)
    {
        scanf("%d", &x[i]);
    }


    bool isSorted=false;
    do
    {
        isSorted=true;
        for (int i=1; i<10; i++)
        {
            if (x[i]>x[i+1])
            {
                int aux=x[i];
                x[i]=x[i+1];
                x[i+1]=aux;
                isSorted=false;
            }
        }
    }while(!isSorted);

    for (int i=1; i<=10; i++)
    {
        printf("%d ", x[i]);
    }
    return 0;
}
