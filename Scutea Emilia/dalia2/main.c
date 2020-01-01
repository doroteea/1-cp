#include <stdio.h>
#include <stdlib.h>

void getaverage(int n, double* res, double* x){
  *res = 0;
  for(int i=0; i<n; i++)
    *res = *res + x[i];
  *res /= n;
}

int main(){
  double x[] = {-1, 2, -5, 3};
  double *p;
  getaverage(sizeof(x)/sizeof(double), p, x);
  printf("media elementelor este %f\n", *p);
  return 0;
}
