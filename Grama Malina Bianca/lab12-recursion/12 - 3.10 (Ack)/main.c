#include <stdio.h>

int Ackermman(int m ,int n)
{
    if (m==0)
    {
        return n+1;
    }
    else
        if (n==0)
        {
            return Ackermman(m-1,1);
        }
        else
            return Ackermman(m-1,Ackermman(m,n-1));

}

int main() {

    int m,n,ack;
    printf("Please write a value for m: ");
    scanf("%d", &m);
    printf("Please write a value for n: ");
    scanf("%d", &n);
    ack=Ackermman(m,n);
    printf("\nValue of Ackermann function is %d.", ack);
    return 0;
}