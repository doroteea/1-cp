/**Given a sequence of n integer numbers, extract the maximum length subsequence which is in ascending order
*/
#include <stdio.h>
#include <stdlib.h>
int n;

void read(int seq[n], int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
    }
}

int maxLength(int seq[n], int n, int l)
{
    int currentLength = 1;
    for(int i = 0; i < n - 1; i++)
    {
        currentLength = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(seq[j - 1] < seq[j])
            {
                currentLength++;
            }
            else
            {
                i = j - 1;
                j = n;
            }
        }
        if(currentLength > l)
        {
            l = currentLength;
        }
    }
    return l;
}

int main()
{
    printf("Read n: ");
    scanf("%d", &n);
    int seq[n];
    printf("Read the sequence: "); read(seq, n);
    printf("%d", maxLength(seq, n, 0));
    return 0;
}
