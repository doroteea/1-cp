#include <stdio.h>
#include <stdlib.h>
#define N 500

int main()
{
    int n,matrice[N][N];
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            scanf("%d",&matrice[i][j]);
    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j)
            if(matrice[i][j]!=matrice[j][i])
            {
                printf("Matricea nu este simetrica");
                return 0;
            }
    printf("Matricea este simetrica");
    return 0;
}
