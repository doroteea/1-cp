#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the amount of money!\n");
    scanf("%d", &n);

    int banknote[]={500, 200, 100, 50, 10, 5, 1};
    int number=0, i=0;
    while (n)
    {
        if (banknote[i]<=n)
        {
            int nr = n/banknote[i];
            number+=nr;
            n%=banknote[i];
        }
        i++;
    }
    printf("The minimum number of banknotes is: %d", number);

    return 0;
}
