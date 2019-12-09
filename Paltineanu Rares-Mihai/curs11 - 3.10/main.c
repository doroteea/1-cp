/**
A simple message  compression method is the  following (run-length):
any sequence of more than three identical characters is replaced by the following triple:
-A control character (marker);-The repeated character;
-A natural number indicating the number of repetitions of that character.
For example, the sequence uuuuuu becomes #u6(if the control character was chosen to be #)
Note there are some issues here:
-The choice of the control character and its representation if it occurs in the message.
-The maximum number of repetitions which can be represented by a single triple.
Write a program to compress/decompress a file using functions for these operations.
The name of the  file  to  process  must  be  passed  as  a  parameter.
Analyze  the  efficiency  of  compression  by comparing the contents of the original with the compressed version.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *txt, FILE *f, char marker) {

    int ct = 0, pos;
    char *aux = (char *)malloc(200);
    memset(aux, '\0', 200);
    int length = 0;

    for(int i = 0; i < strlen(txt); i++) {

        if(txt[i] == ' ') {

            aux[length++] = ' ';

        } else {
            if(txt[i] == txt[i + 1]) {

                pos = i;
                ct = 1;

                while(i < strlen(txt) && txt[i] == txt[i + 1]) {

                    ct++;
                    i++;

                }

                aux[length++] = marker;
                aux[length++] = txt[pos];

                if(ct > 99) {

                    aux[length++] = (ct / 100) + '0';
                    ct = ct % 100;

                }

                if(ct > 9) {

                    aux[length++] = (ct / 10) + '0';
                    ct = ct % 10;

                }

                aux[length++] = ct + '0';

            }
            else {

                while(txt[i] != txt[i + 1] && i < strlen(txt)) {

                    aux[length++] = txt[i++];

                }

                i--;

            }
        }
    }

    strcpy(txt, aux);
}

void decompress(char *txt, FILE *file, char marker) {

    char *aux = (char *)malloc(200);
    memset(aux, '\0', 200);
    int length = 0;
    int ct = 0;
    char character;
    puts(txt);

    for(int i = 0 ; i < strlen(txt); i++) {

        while(txt[i] != marker) {

            aux[length++] = txt[i++];

        }

        character = txt[i + 1];
        i = i + 2;

        while(txt[i] >= '0' && txt[i] <= '9') {

            ct = ct * 10 + txt[i] - '0';
            i++;

        }

        for(int j = 0; j < ct; j++) {

            aux[length++] = character;


        }
        i--;
        ct = 0;
    }

    puts(aux);
}

int main() {
    FILE *file;
    file = fopen("11.txt", "rw");

    if(file == NULL) {

        return -1;

    }
    char marker;

    char *text1 = (char *)malloc(200);
    fscanf(file, "%c %[^\n]", &marker, text1);
    puts(text1);

    compress(text1, file, marker);
    puts(text1);

    decompress(text1, file, marker);
    return 0;
}
