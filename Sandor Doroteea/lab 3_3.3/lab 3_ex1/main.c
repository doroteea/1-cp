//
//  main.c
//  lab 3_ex1
//
//  Created by Sandor Doroteea on 10/16/19.
//  Copyright © 2019 Doroteea Sandor. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x,maxv,minv,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(i==1){
            maxv=x;
            minv=x;
        }
        if(maxv<x)
            maxv=x;
        if(minv>x)
            minv=x;
    }
    printf("Maxim este=%d\n",maxv);
    printf("Minim este=%d\n",minv);
    
    return 0;
}
