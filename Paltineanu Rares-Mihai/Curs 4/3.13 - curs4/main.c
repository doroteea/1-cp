/*
Given a sequence of n real numbers sorted in ascending order,
verify if a given value, x,exists in the given sequence, and display this value and its position
*/
#include <stdio.h>
#include <stdlib.h>

int n, x, a;


int verify(double seq[n], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        if(seq[i] > seq[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

void read(double seq[n], int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &seq[i]);
    }
}

int search(double seq[n], int n, int x)
{
    int left = 0, right = n - 1,mid, find = -1;
    printf("%d %d\n", left, right);
    while(left < right && find == -1)
    {
        mid = (left + right) / 2;

        if(seq[mid] == x)
        {
            find = mid;
        }
        else if(seq[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        printf("%d %d\n", left, right);
    }
    return find;
}

int main()
{
    printf("Read n and x: ");
    scanf("%d %d", &n, &x);
    double seq[n]; ///Is it ok if i put the dimension of the array like this?
    //printf("%d", sizeof(double));
    //memset(seq, 0, n * 8);
    printf("Read the sequence: ");
    read(seq, n);

    while(!verify(seq, n))
    {
        printf("Read the sequence of %d real numbers in ascending order: ");
        read(seq, n);
    }

    a =search(seq, n, x);
    if(a == -1)
    {
        printf("The number %d does not exist in the sequence.", x);
    }
    else
    {
        printf("The number %d exists in the sequence on the position %d", x, a);
    }
    return 0;
}
