//
//  main.c
//  3.6
//
//  Created by Sandor Doroteea on 10/22/19.
//  Copyright © 2019 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n,m,pal=0;
    scanf("%d",&n);
    m=n;
    while(n)
    {
        pal=pal*10+n%10;
        n=n/10;
    }
    if(pal==m)
        printf("It seems that's a palindom =%d\n",pal);
    return 0;
}
