#include "students.h"
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    printf("Input how many students you'll read:\nn=");
    scanf("%d", &n);
    student *students = readStudents(n);
    /*int **lexico = (int **) malloc(sizeof(int) * MAX_STUDENT_NAME_LENGTH);
    for (int i = 0; i < n; i++) {
        *(lexico + i) = (int *) malloc(sizeof(int) * MAX_STUDENT_NAME_LENGTH);
    }
    for (int i = 0; i < n; i++) {
        int length = strlen(students[i].name);
        for (int j = 0; j < length; j++) {
            lexico[i][j] = 'z' - tolower(students[i].name[j]);
        }
    }*/
    /* int j=0;
     int *counter=(int*)malloc(sizeof(int)*n);
     for (int i=0;i<n;i++){
         counter[i]=0;
     }
     for (int i=0;i<n-1;i++) {
         for (int a = i + 1; a < n; a++) {
             while (students[i].name[j] == students[a].name[j]) {
                 j++;
             }
             if (students[i].name[j] > students[a].name[j]) {
                 counter[i]++;
             } else counter[a]++;
         }
     }*/


// strncmp intre nume de la stringuri, vezi modificare struct sau ce faci daca un nume e dupa celalalt?
    for(int i=0;i<n-1;i++){
        for (int j=i+1;j<n-1;j++){
            if  (strcmp(students[i].name, students[j].name) >0 ){
                students[i].name=students[j].name;
            }
        }
    }
    printf("The students ordered in lexicographic order, along with their adresses and birthnames are:\n");
    for (int i=0;i<n;i++){
        printf("%s \n %s \n %d/%d/%d\n \n", students[i].name,students[i].address,students[i].dateOfBirth.day,students[i].dateOfBirth.month,students[i].dateOfBirth.year);
    }
    return 0;
}