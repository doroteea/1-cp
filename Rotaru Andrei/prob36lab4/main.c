#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,inverse,copy;
    printf("Introduce n: ");
    scanf("%d",&n);
    inverse=0;
    copy=n;
    while(n!=0){
        inverse=inverse*10+n%10;
        n/=10;
    }
    if (copy==inverse){
        printf("\n%d is a palindrome \n",copy);
    }
    else{
        printf("\n%d is not a palindrome \n",copy);
    }
return 0;
}
