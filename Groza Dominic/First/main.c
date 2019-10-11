#include <stdio.h>
#include <string.h>

int main(){
        float age;
        float heightcm;
        char gender [10];
    double W_male = 50+0.75*(heightcm-150)+(age-20)/4;
    double W_fema = W_male -10;
    printf ("Enter your gender (male or female) ,your height (centimeters) and your age\n");
    scanf ("%s,%f,%f",&gender,&heightcm,&age);
    if (strcmp(gender,"male")==0){
        printf("%d",W_male);}
        else{
           printf("%d",W_fema);
    }
    return 0;

}