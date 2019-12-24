#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getApparitionVector(long n)
{
    int *apparitionVector=(int*)malloc(sizeof(int)*10);
    while(n!=0)
    {
        int digit=n%10;
        apparitionVector[digit]=1;
        n=n/10;
    }
    return apparitionVector;
}

long getReversedNr(long n)
{
    long reverseNr=0;
    while(n!=0)
    {
        int digit=n%10;
        reverseNr=reverseNr*10+digit;
        n=n/10;
    }
    return reverseNr;
}
long computeNumberDigitsOneAppeareance(long n)
{
    long nr=0;
    int *apparitionVector=getApparitionVector(n);
    long reversedNr=getReversedNr(n);
    while(reversedNr!=0)
    {
        int digit=reversedNr%10;
        if(apparitionVector[digit]==1)
        {
            nr=nr*10+digit;
            apparitionVector[digit]=0;
        }
        reversedNr=reversedNr/10;
    }
    return nr;
}
int getFrequencyVector(long n)
{
    int *frequencyVector=(int*)malloc(sizeof(int)*10);
    memset(frequencyVector,0,10);
    while(n!=0)
    {
        int digit=n%10;
        frequencyVector[digit]++;
        n=n/10;
    }
    return frequencyVector;
}
long getBiggestNumber(long n)
{
    int *frequencyVector=getFrequencyVector(n);
    long biggestNr=0;
    for(int i=9; i>=0; i--)
    {
        while(frequencyVector[i]!=0)
        {
            biggestNr=biggestNr*10+i;
            frequencyVector[i]=frequencyVector[i]-1;
        }
    }
    return biggestNr;
}

int main()
{
    long n;
    printf("Please insert the number:\nn=");
    scanf("%ld",&n);
    long nr1=computeNumberDigitsOneAppeareance(n);
    printf("a) The number obtained by eliminating those digits that appear more than once in that number is %ld.\n",nr1);
    long nr2=getReversedNr(n);
    printf("b) The number obtained by switching the digits is: %ld.\n",nr2);
    long nr3=getBiggestNumber(n);
    printf("c) The biggest number that could be obtained by a combination of its digits is %ld .",nr3);
}
