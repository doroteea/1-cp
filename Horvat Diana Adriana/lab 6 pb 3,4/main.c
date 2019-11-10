#include <stdio.h>
#include <stdlib.h>
float *v,*u,*w;
int n,m,k;
int main()
{
    scanf("%d",&n);
    float *v=(float*)malloc(sizeof(float)*n);
    for(int i=0; i<n; i++)
    {
        scanf("%f",&v[i]);
    }

    scanf("%d",&m);
    float *u=(float*)malloc(sizeof(float)*m);
    for(int i=0; i<m; i++)
    {
        scanf("%f",&u[i]);
    }
    float *w=(float*)malloc(sizeof(float)*(n+m));

    if(n>=m)
    {
        int i=0,j=0;
        k=-1;
        while(i<=m && j<=m)
        {
            if(v[i]>=u[j] && w[k-1]!=u[j])
            {
                k=k+1;
                w[k]=u[j];
                j=j+1;
            }
            else
            {
                if(v[i]<u[j] && w[k-1]!=v[i])
                {
                    k=k+1;
                    w[k]=v[i];
                    i=i+1;
                }
            }
        }
        while(i<=n)
        {
            k=k+1;
            w[k]=v[i];
            i=i+1;
        }

    }
    else
    {
        int i=0,j=0;
        k=-1;
        while(i<=n && j<=n)
        {
            if(v[i]>=u[j] && w[k-1]!=u[j])
            {
                k=k+1;
                w[k]=u[j];
                j=j+1;
            }
            else
            {
                if(v[i]<u[j] && w[k-1]!=v[i])
                {
                    k=k+1;
                    w[k]=v[i];
                    i=i+1;
                }
            }
        }
        while(j<=m)
        {
            k=k+1;
            w[k]=u[j];
            j=j+1;
        }
    }

    for(int i=0; i<k; i++)
    {
        printf(" %f",w[i]);
    }




    return 0;
}
