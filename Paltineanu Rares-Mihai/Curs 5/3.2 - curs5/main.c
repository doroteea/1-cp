/**Read the degree of a polynomial and its coefficients, all integers, from the standard input.
The polynomial has only simpleinteger roots. Find its roots.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;

void readPol(int *pol) {

    for(int i = 0; i < n; i++) {
        scanf("%d", &pol[i]);
    }
}

int main() {

    scanf("%d", &n);
    int pol[n]; memset(pol, 0, sizeof(pol));
    readPol(pol);
    /*
    int *j = (int *)malloc(4);
    *j = 10;
    printf("%d", *j);
    */
    return 0;
}
