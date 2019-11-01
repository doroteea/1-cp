/**Write a function to check if its parameter (positive integer) is a perfect square.
Then apply this function to a vector of positive integers, and extract all perfect squares and place them in another vector.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;

void read(int *vect) {

    for(int i = 0; i < n; i++) {
        scanf("%d", &vect[i]);
    }
}

void write(int *s, int n) {

    for(int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
}


int square(int nr) {

    if(floor(sqrt(nr)) * floor(sqrt(nr)) == nr)
        return 1;

    return 0;
}

int main() {

    scanf("%d", &n);
    int vect[n]; memset(vect, 0, sizeof(int) * n);
    int perfect[n]; memset(perfect, 0, sizeof(int) * n);
    int sizePerfect = 0;
    read(vect);

    for(int i = 0; i < n; i++) {
        if(square(vect[i])) {
            perfect[sizePerfect++] = vect[i];
        }
    }
    if(sizePerfect != 0){
    write(perfect, sizePerfect);
    }
    else {
        printf("The array does not have perfect squares");
    }
    return 0;

}
