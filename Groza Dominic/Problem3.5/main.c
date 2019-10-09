#include <stdio.h>

int main() {
    int x;
    int y;
    scanf("%d", &x);
    if (x < -2) {
        y = x * x - 7 * x + 4;
    } else if (x == -2) {
        y = 0;
    } else {
        y = x * x + 5 * x - 2;
    }
    printf("%d", y);
    return 0;
}