#include <stdio.h>
#include <stdlib.h>

void mergeVect(int *s1, int size1, int *s2, int size2, int *s3, int *size3) {

    int a = 0, b = 0;

    while(a < size1 && b < size2) {


        if(size3 == 0) {

            if(s1[a] < s2[b]) {

                s3[0] = s1[a];
                (*size3)++;
                a++;

            } else {

                s3[0] = s2[b];
                (*size3)++;
                b++;

            }

        }

        if(s1[a] < s2[b]) {
            if(s1[a] != s3[*size3 - 1]) {

                s3[*size3] = s1[a];
                (*size3)++;
                a++;

            } else {
                a++;
            }
        }

        if(s2[b] < s1[a]) {
            if(s2[b] != s3[*size3 - 1]) {

                s3[*size3] = s2[b];
                (*size3)++;
                b++;

            } else {
                b++;
            }
        }

        if(s1[a] == s2[b]) {
            if(s1[a] != s3[*size3 - 1]) {

                s3[*size3] = s1[a];
                (*size3)++;
                a++;
                b++;

            } else {
                a++;
                b++;
            }
        }

    }

    while(a < size1) {

        if(s3[*size3 - 1] != s1[a]) {

            s3[*size3] = s1[a];
            (*size3)++;
            a++;

        } else {
            a++;
        }


    }

    while(b < size2) {
        if(s3[*size3 - 1] != s2[b]) {

            s3[*size3] = s2[b];
            (*size3)++;
            b++;

        } else {
            b++;
        }
    }

}
