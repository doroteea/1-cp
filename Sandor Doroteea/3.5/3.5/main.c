//
//  main.c
//  3.5
//
//  Created by Sandor Doroteea on 10/22/19.
//  Copyright © 2019 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int p=sqrt(n);
    printf("the greatest perfect square = %d\n",p);
    int d,ok=1;
    if(n==2)
        printf("the least prime number = %d\n",n);
    do
        {
            ok=1;
            for(d=2;d<n/2;d++)
                if(n%d==0)
                    ok=0;
            if(ok==0)
               n++;
        }while(ok==0);
        printf("the least prime number = %d\n",n);
    return 0;
}
