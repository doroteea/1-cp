#include <stdio.h>
#include <stdlib.h>
void AscendingSort(int Sequence[100],int n)
{
    int aux;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        if(Sequence[j]<Sequence[i])
    {aux=Sequence[j];
    Sequence[j]=Sequence[i];
    Sequence[i]=aux;
    }
}
int main()
{
  int Sequence[100],n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {scanf("%d",&Sequence[i]);}
AscendingSort(Sequence,n);
for(int i=0;i<n;i++)
    {printf("%d ",Sequence[i]);}
    return 0;
}
