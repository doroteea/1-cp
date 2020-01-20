#include <stdio.h>
#include <stdlib.h>
int n;
float Sequence[100],x;
void BinarySearch(float SearchedNumber,int *Position)
{
    int middle,left=0,right=n-1;
    *Position=-1;//the position will remain -1 if the SearchedNumber isn't found amongst the sequence.
    while(left<=right)
    {
        middle=(left+right)/2;
        if(SearchedNumber==Sequence[middle])
        {
            right=left-1;//This will ensure us that the repetitive structure will terminate.
            *Position=middle;
        }
        else if(SearchedNumber<Sequence[middle])
        {
            right=middle-1;
        }
        else
        {
            left=middle+1;
        }

    }
}
int main()
{
    int position;
    printf("Give the lenght of the sequence:");
    scanf("%d",&n);
    printf("Give the value you are looking for:");
    scanf("%f",&x);
    printf("Give the values of the sequence:");
    for(int i=0; i<n; i++)
    {
        scanf("%f",&Sequence[i]);
    }
    BinarySearch(x,&position);
    if(position==-1)
    {
        printf("The number %f has not been found in the given sequence.",x);
    }
    else
    {
        printf("The number %f has been found at the position %d.",x,position);
    }
    return 0;
}
