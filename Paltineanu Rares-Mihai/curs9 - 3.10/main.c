/**
Read  from  the  keyboard  strings  of at  most 80  characters,  representing  integer  or  real  non-exponential numbers, separated by spaces.
Compute the sum of the real numbers and of the integer numbers of each string, except the incorrect values.
An incorrect value is a character string delimited by spaces, containing non-numeric characters, or having the length greater than 5.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocMat(int n) {

    char **mat = (char **)malloc(sizeof(char *) * n);

    for(int i = 0; i < n; i++) {
        mat[i] = (char *)malloc(sizeof(char) * 81);

    }

    return mat;
}

void readMat(char **mat, int n) {

    for(int i = 0; i < n; i++) {
        gets(mat[i]);
    }
}

int verify(char *vect) {

    int sizeString;

    sizeString = strlen(vect);

    for(int i = 0; i < sizeString; i++) {


        if(   vect[i] != '0' && vect[i] != '1' && vect[i] != '2' && vect[i] != '3' && vect[i] != '4'
                && vect[i] != '5' && vect[i] != '6' && vect[i] != '7' && vect[i] != '8' && vect[i] != '9'
                && vect[i] != '.') {

            return 0;

        }
    }

    return 1;

}

int countRealOrInt(char **mat, int n, int intOrReal) {

    for(int i = 0; i < n; i++) {

        if(intOrReal == 1) {

            if(verify(mat[i]) == 1 && strchr(mat[i], '.') == NULL) {

                return 1;

            }
        } else {

            if(verify(mat[i]) == 1 && strchr(mat[i], '.') != NULL) {

                return 1;

            }
        }
    }

    return 0;
}

char *performingAdditionInt(char *vect1, char *vect2) {

    int transport = 0;
    int val;
    int sizeString1, sizeString2;

    sizeString1 = strlen(vect1) - 1;
    sizeString2 = strlen(vect2) - 1;

    for(int i = sizeString1; i >= 0; i--) {

        val = (vect1[i] - '0') + (vect2[sizeString2] - '0') + transport;

        if(val >= 10) {

            val -= 10;
            transport = 1;

        } else {

            transport = 0;

        }

        vect2[sizeString2] = val + '0';
        sizeString2--;

    }

    while(sizeString2 >= 0 && transport ==1) {

        val = vect2[sizeString2] - '0' + transport;

        if(val >= 10) {

            val -= 10;
            transport = 1;

        } else {

            transport = 0;

        }

        vect2[sizeString2] = val + '0';
        sizeString2--;

    }

    if(transport == 1) {

        strcpy(vect2 + 1, vect2);
        vect2[0] = '1';
        transport = 0;

    }


    return vect2;
}

char *performingAdditionReal(char *vect1, char *vect2, int *transport) {

    int sizeString1 = strlen(vect1) - 1;
    // sizeString2 = strlen(vect2) - 1;
    int size = sizeString1, val;

    for(int i = sizeString1; i >= 0; i--) {

        val = (vect1[i] - '0') + (vect2[size] - '0') + *transport;

        if(val >= 10) {

            val -= 10;
            (*transport)++;

        } else {

            *transport = 0;

        }

        vect2[size] = val + '0';
        size--;
    }

    return vect2;
}

void additionIntegers(char **mat, int n, char *vect) {

    int firstElem = 0;

    for(int i = 0; i < n; i++) {

        if(verify(mat[i]) == 1) {

            if(strchr(mat[i], '.') == NULL) {

                if(firstElem == 0) {

                    strcpy(vect, mat[i]);
                    firstElem++;

                } else {

                    if(strlen(mat[i]) > strlen(vect)) {

                        vect = performingAdditionInt(vect, mat[i]);

                    } else {

                        vect = performingAdditionInt(mat[i], vect);

                    }

                }
            }
        }
    }

    printf("The addition of the integer numbers is: ");
    puts(vect);
}

void additionReal(char **mat, int n, char *vect) {

    int firstElem = 0;
    int transport = 0;
    char realPart1[100], realPart2[100];
    char intPart1[100], intPart2[100];
    int size, val;

    memset(realPart1, '\0', 100);
    memset(realPart2, '\0', 100);
    memset(intPart1, '\0', 100);
    memset(intPart2, '\0', 100);

    for(int i = 0; i < n; i++) {

        if(verify(mat[i]) == 1) {

            if(strchr(mat[i], '.') != NULL) {

                if(firstElem == 0) {

                    strcpy(vect, mat[i]);
                    firstElem++;

                } else {

                    strcpy(realPart1, strchr(mat[i], '.') + 1);
                    strcpy(realPart2, strchr(vect, '.') + 1);

                    if(strlen(realPart1) > strlen(realPart2)) {

                        *realPart2 = performingAdditionReal(realPart2, realPart1, &transport);

                    } else {

                        *realPart2 = performingAdditionReal(realPart1, realPart2, &transport);

                    }

                    strncpy(intPart1, mat[i], strlen(mat[i]) - strlen(strchr(mat[i], '.')));
                    intPart1[strlen(intPart1)] = '\0';

                    strncpy(intPart2, vect, strlen(vect) - strlen(strchr(vect, '.')));
                    intPart2[strlen(intPart2)] = '\0';


                    if(transport == 1) {

                        size = strlen(intPart1) - 1;

                        while(size >= 0 && transport == 1) {

                            val = intPart1[size] - '0' + transport;
                            if(val >= 10) {

                                val -= 10;
                                transport = 1;
                            } else {

                                transport = 0;

                            }

                            intPart1[size] = val + '0';
                            size--;
                        }

                    }

                    if(strlen(intPart1) > strlen(intPart2)) {

                        *intPart2 = performingAdditionInt(intPart2, intPart1);

                    } else {

                        *intPart2 = performingAdditionInt(intPart1, intPart2);

                    }

                    strcpy(vect, intPart2);
                    vect[strlen(vect)] = '.';
                    vect[strlen(vect)] = '\0';
                    strcat(vect, realPart2);
                    vect[strlen(vect)] = '\0';

                }
            }
        }
    }

    printf("The addition on the real numbers is: ");
    puts(vect);
}

/// i tried to pass function pointer as parameter, but i failed, it was something like this:
/**

void addition(char **mat, int n, char *vect, void (*add)(char, int, char) {


    add(mat, n, vect);
}
*/
///i didnt find something on the internet and i did it how i thought it should be

int main() {

    int n;
    printf("Read the no. of strings: ");
    scanf("%d", &n);
    getchar();

    char **mat = allocMat(n);
    printf("Read the strings: ");
    readMat(mat, n);

    char *addInt = (char *)malloc(sizeof(char) * 82);
    char *addReal = (char *)malloc(sizeof(char) * 82);

    if(countRealOrInt(mat, n, 1) == 1) {

        additionIntegers(mat, n, addInt);

    }

    if(countRealOrInt(mat, n, 0) == 1) {

        additionReal(mat, n, addReal);

    }

    return 0;
}
