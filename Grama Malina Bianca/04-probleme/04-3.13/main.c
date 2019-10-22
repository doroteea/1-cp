#include <stdio.h>

int n,x,v[100],m,i,position;

int search (int s, int d)
{
    if(s>d)
        return -1;
    else
    {
        m=(s+d)/2;
        if (x==v[m])
            return m;
        if (x<v[m])
            return search(s,m-1);
        else
            return search(m+1,d);
    }
}

int main()
{
    printf("Length of sequence: ");
    scanf("%d", &n);
    printf("Sequence: ");

    for (i=1;i<=n;i++)
    {
        scanf("%d ", &v[i]);
    }

    scanf("%d", &x);

    position=search(1,n);

    if (position == -1)
    {
        printf("The number does not exist in the sequence \n");
    }
    else
    {
        printf("The element %d has been found on the position %d", x,position );
    }

    return 0;
}