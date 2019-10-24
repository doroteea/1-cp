/**Two character strings representing very large decimal integers are given.
Write a program to perform arithmetic operations with such very large decimal integers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///It's only the addition, in this weekend maybe i will do the subtraction and multiplication
///I just want to know if what i did is ok

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

int main() {

    char nr1[100], nr2[100], nr3[100];

    memset(nr1, '\0', sizeof(nr1));
    memset(nr2, '\0', sizeof(nr2));
    memset(nr3, '\0', sizeof(nr3));

    gets(nr1);
    gets(nr2);

    addition(nr1, nr2, nr3);

    strrev(nr3);

    puts(nr3);

    return 0;

}
