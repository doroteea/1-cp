/**Given a real number a written in base 10,  write a program to convert this number in base B, whereB≤ 16
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertOver10(int dec, int B) {

    char vect[100];
    int size = 0;

    while(dec != 0) {
        if(dec % B < 10) {
            vect[size++] = dec + '0';
        }
        else {
            vect[size++] = 'A' + (dec % B) - 10;
        }
        dec /= B;
    }

    vect[size] = '\0';
    strrev(vect);

    for(int i = 0; i < size; i++) {
        printf("%c", vect[i]);
    }

}

void convertUnder10(int dec, int B) {

    int vect[100], size = 0, temporary;

    while(dec != 0) {

        vect[size++] = dec % B;
        dec /= B;

    }

    for(int i = 0; i < size/2; i++) {

        temporary = vect[i];
        vect[i] = vect[size - i-1];
        vect[size - i-1] = temporary;

    }

    for(int i = 0; i < size; i++) {
        printf("%d", vect[i]);
    }

}

int main() {

    int dec, B;
    printf("Read the number and the base: ");
    scanf("%d %d", &dec, &B);
    printf("The number %d in base %d is: ", dec, B);
    if(B < 9) {
        convertUnder10(dec, B);
    }
    else if(B == 10) {
        printf("%d", dec);
    }
    else {
        convertOver10(dec, B);
    }
    return 0;

}
