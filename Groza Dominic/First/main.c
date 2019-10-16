#include <stdio.h>
#include <string.h>

int main() {
    char gender[10];
    double W_male, W_female, age, heightcm;
    printf("Enter your gender (male or female) ,your height (centimeters) and your age\n");
    scanf("%s", &gender);
    scanf("%Lf", &heightcm);
    scanf("%Lf", &age);
    W_male = 50 + 0.75 * (heightcm - 150) + (age - 20) / 4;
    W_female = W_male - 10;
    if (strcmp(gender, "male") == 0) {
        printf("%Lf", W_male);
    } else {
        printf("%Lf", W_female);
    }
    return 0;

}