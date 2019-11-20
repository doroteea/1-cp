/**Write a modular program which reads student related data for a group, namely:
name, date of birth, residence address, and prints them in lexicographic order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "read.h"

int main() {

    int n;
    student *group = (student *)malloc(sizeof(student)  * 100);

    printf("Enter the number of students: ");
    scanf("%d", &n);

    initialize(group, n);

    read(group, n);

    lexicographicSort(group, n);

    write(group, n);

    return 0;

}
