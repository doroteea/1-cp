/**Two character strings representing very large decimal integers are given.
Write a program to perform arithmetic operations with such very large decimal integers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int colNr4 = 0, rowNr4 = 0;

///I just did the multiplication

void addition(char *s1, char *s2, char *s3) {

    int size1 = strlen(s1), size2 = strlen(s2);

    int sizemax = size1 > size2 ? size1 : size2;

    int transport = 0, value, size3 = 0;

    for(int i = sizemax - 1; i >= 0 && size1 > 0 && size2 > 0; i--) {

        value = (s1[size1 - 1] - '0') + (s2[size2 - 1] - '0') + transport;
        size1--;
        size2--;

        if(value < 10) {

            s3[size3++] = value + '0';
            transport = 0;

        } else {

            transport = 1;
            value -= 10;
            s3[size3++] = value + '0';

        }

    }

    for(int i = size1 - 1; i >= 0; i--) {

        if(transport != 0) {
            value = s1[i] - '0' + transport;
            if(value < 10) {

                s3[size3++] = value + '0';
                transport = 0;

            } else {

                transport = 1;
                value -= 10;
                s3[size3++] = value + '0';

            }
        } else {
            s3[size3++] = s1[i];
        }
    }

    for(int i = size2 - 1; i >= 0; i--) {

        if(transport != 0) {
            value = s2[i] - '0' + transport;
            if(value < 10) {

                s3[size3++] = value + '0';
                transport = 0;

            } else {

                transport = 1;
                value -= 10;
                s3[size3++] = value + '0';

            }
        } else
            s3[size3++] = s2[i];
    }

    if(transport == 1)
        s3[size3++] = transport + '0';

}


void multiplication(char *s1, char *s2, char s3[100][200]) {

    int size1 = strlen(s1) - 1, size2 = strlen(s2) - 1, size1Constant = strlen(s1), size2Constant = strlen(s2);
    int transport = 0, value, rows = 1, columns = 1, lastLetter = 0;

    while(lastLetter != size1Constant) {
        if(size1 < 0 && transport != 0) {

            s3[rows - 1][columns - 1] = transport + '0';
            columns++;

        }

        if(columns > colNr4) {
            colNr4 = columns;
        }

        if(size1 < 0) {

            size1 = size1Constant - 1;
            size2--;
            rows++;
            columns = rows;
            transport = 0;
            lastLetter++;
            size2 = size2Constant-1 - lastLetter;

        }

        value = (s1[size1] - '0') * (s2[size2] - '0') + transport;
        size1--;
        transport = value / 10;
        value = value % 10;
        s3[rows - 1][columns - 1] = value + '0';
        columns++;

    }

    rowNr4 = rows;

}

void additionMultiplication(char *s1, char nr4[100][200]) {

    int value = 0, transport = 0, size = 0;

    for(int i = 0; i < colNr4 - 1; i++) {

        for(int j = 0; j < rowNr4 - 1; j++) {

            if(nr4[j][i] != '\0') {
                value = value + (nr4[j][i] - '0');
            }

        }

        value += transport;

        if(value > 9) {

            transport = value / 10;
            value = value % 10;

        } else {
            transport = 0;
        }

        s1[size] = value + '0';
        value = 0;
        size++;

    }

}

int main() {

    char nr1[100], nr2[100], nr3[200], nr4[100][200];

    memset(nr1, '\0', sizeof(nr1));
    memset(nr2, '\0', sizeof(nr2));
    memset(nr3, '\0', sizeof(nr3));
    memset(nr4, '\0', sizeof(nr4));

    gets(nr1);
    gets(nr2);

    addition(nr1, nr2, nr3);
    strrev(nr3);
    printf("The addition of the numbers is equal to: ");
    puts(nr3);

    if(strlen(nr1) < strlen(nr2)) {
        strcpy(nr3, nr1);
        strcpy(nr1, nr2);
        strcpy(nr2, nr3);
    }

    nr3[0] = '\0';
    ///memset(nr3, '\0', sizeof(nr3));

    multiplication(nr1, nr2, nr4);
    additionMultiplication(nr3, nr4);
    strrev(nr3);

    if(nr3[0]== '0') {
        strcpy(nr3, nr3 + 1);
    }

    printf("The multiplication of the numbers is equal to: ");
    puts(nr3);

    return 0;

}
