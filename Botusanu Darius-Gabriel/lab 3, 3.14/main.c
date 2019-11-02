#include <stdio.h>
#include <stdlib.h>
/*Now these are some unrealistic standards for weight...*/
int main()
{
   float w_male, w_female, h_m, age;
   printf("\nInput the height (in cm) and age: ");    scanf("%f %f", &h_m, &age);
   w_male = 50 + 0.75*(h_m-150) + (age-20)/4;
   w_female= w_male - 10;
   printf("\nThis is the ideal weight for a male %2.f", w_male);
   printf("\nThis is the ideal weight for a female %2.f", w_female);
   return 0;

}
