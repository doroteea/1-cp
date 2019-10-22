#include <stdio.h>
#include <stdlib.h>

int main()
{
    float seq[40],givenNumber;
    int number,i,position,verify;
    scanf("%d",&number);
    verify=0;
    for(i=0;i<number;i++)
    {
        scanf("%f",&seq[i]);
    }
    scanf("%f",&givenNumber);
    for(i=0;i<number;i++)
    {
        if(seq[i]==givenNumber)
        {
            verify=1;
          position=i;
          printf("The value is %.2f  with its position %d",givenNumber,position);
          break;
        }

    }
    if(verify==0)
    {
        printf("The value does not exist in the sequence");
    }

    return 0;
}
