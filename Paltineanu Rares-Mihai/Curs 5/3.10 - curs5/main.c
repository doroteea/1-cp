/**Read an integer representing an amount of money expressed in RONfrom the standard input.
Write a function to determine the minimum number of banknotes needed to pay that amount.
*/
#include <stdio.h>
#include <stdlib.h>

void banknotes(int *RON, int *ct, int money) {

    while(*RON >= money) {
        *RON -= money;
        (*ct)++;
        printf("%d  ", money);
    }

}

int main() {

    int RON, ct = 0; scanf("%d", &RON);
    banknotes(&RON, &ct, 500);
    banknotes(&RON, &ct, 200);
    banknotes(&RON, &ct, 100);
    banknotes(&RON, &ct, 50);
    banknotes(&RON, &ct, 10);
    banknotes(&RON, &ct, 5);
    banknotes(&RON, &ct, 1);
    printf("The number of banknots needed is: %d.", ct);
    return 0;

}
