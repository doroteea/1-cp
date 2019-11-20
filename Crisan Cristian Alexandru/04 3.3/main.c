#include <stdio.h>
#include <stdlib.h>
/*3.3. Real numbers of a sequence of size n
are read from the standard input.
Find and print to standard output: the minimum and the maximum
values of this sequence, and their positions (indices) in the sequence. */
int main()
{
    int RealNumberSequence[100],n,Maximum,Minimum,MaximumIndice,MinimumIndice;
    scanf("%d",&n);
    scanf("%d",&RealNumberSequence[0]);

    Minimum=RealNumberSequence[0];
    Maximum=Minimum;
    MaximumIndice=0;
    MinimumIndice=0;
    for(int i=1;i<n;i++)
    {scanf("%d",&RealNumberSequence[i]);
          if(RealNumberSequence[i]>Maximum)
          {
              Maximum=RealNumberSequence[i];
              MaximumIndice=i;
          }
          else if(RealNumberSequence[i]<Minimum)
          {
              Minimum=RealNumberSequence[i];
              MinimumIndice=i;
          }
    }
    printf("The maximum value %d from the sequence is found at the position %d.\n",Maximum,MaximumIndice);
       printf("The minimum value %d from the sequence is found at the position %d.\n",Minimum,MinimumIndice);


    return 0;
}
