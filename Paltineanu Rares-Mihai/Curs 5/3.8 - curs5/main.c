/**Write a function which has a string of characters representing a number written using Roman numerals as a parameter,
and returns the corresponding radix(base)10 Arabian  number.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanLetters(char c) {

    if(c == 'I')
        return 1;

    if(c == 'V')
        return 5;

    if(c == 'X')
        return 10;

    if(c == 'L')
        return 50;

    if(c == 'C')
        return 100;

    if(c == 'D')
        return 500;

    if(c == 'M')
        return 1000;

}

int conversion(char *Roman, int nr) {

    int size = strlen(Roman), currentValue, lastLetter = 0;

    for(int i = 0; i < size - 1; i++) {
        currentValue = romanLetters(Roman[i]);
        if(currentValue == romanLetters(Roman[i + 1]) || currentValue > romanLetters(Roman[i + 1])) {
            if(i == size - 2) {
                nr += currentValue;
                lastLetter = 1;
            }
            else {
                nr += currentValue;
            }
        } else {
            nr += romanLetters(Roman[i + 1]) - currentValue;
            i++;
        }
    }
    if(lastLetter == 1)
        nr += romanLetters(Roman[size - 1]);
    return nr;
}

int main() {

    char Roman[50];
    memset(Roman, '\0', sizeof(Roman));
    gets(Roman);

    printf("%d",conversion(Roman,0));
    return 0;

}
