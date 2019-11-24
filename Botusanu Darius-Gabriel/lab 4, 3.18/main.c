#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long getReversedNumber(long number)
{
    int reversedNumber=0;
    while(number!=0)
    {
        reversedNumber=reversedNumber*10+number%10;
        number/=10;
    }
    return reversedNumber;
}

int * getApparitionVector(long number)
{
    int * apparitionVector=(int*)malloc(sizeof(long)*10);
    while(number!=0)
    {
        int digit=number%10;
        apparitionVector[digit]=1;
        number/=10;
    }
    return apparitionVector;
}

long getDinstinctNumber(long number)
{
    int distinctNumber=0;
    int * apparitionVector=getApparitionVector(number);
    while(number!=0)
    {
        int digit=number%10;
        if(apparitionVector[digit]==1)
        {
            distinctNumber=distinctNumber*10+digit;
            apparitionVector[digit]=0;
        }
        number/=10;
    }
    return getReversedNumber(distinctNumber);

}



int * getFrequencyVector(long number)
{
    int * frequencyVector=(int*)malloc(sizeof(long)*10);
    memset(frequencyVector,0,10);
    while(number!=0)
    {
        int digit=number%10;
        frequencyVector[digit]++;
        number/=10;
    }
    return frequencyVector;
}

long getBiggestNumber(long number)
{
    int * frequencyVector=getFrequencyVector(number);
    int biggestNumber=0;
    int i;
    for(i=9; i<=0; --i)
    {
        biggestNumber=biggestNumber*10+frequencyVector[i];

    }
    return biggestNumber;

}

long readNumber()
{
    long number;
    printf("Please input a number:");
    scanf("%ld",&number);
    return number;

}
int main()
{
    long number=readNumber();
    printf("\na)This is the number without any repeating digits: %ld", getDinstinctNumber(number));
    printf("\nb)This is the number reversed: %ld", getReversedNumber(number));
    printf("\nc)This is the biggest number made out of the digits of the original number: %ld", getBiggestNumber(number));
    return 0;
}
