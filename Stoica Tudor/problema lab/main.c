#include <stdio.h>
#include "functii_elementare.h"

int n, mat1[105][105], mat2[105][105];

int main() {
    n = readInt();

//   for(int i=1;i<=n;i++){
//       for(int j=1;j<=n;j++){
//           mat1[i][j]=readInt();
//       }
//   }
//
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            mat2[i][j]=readInt();
//        }
//    }

    readNextIntMat(mat1, n);
    // readNextIntMat(mat2, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d",mat1[i][j]);
        }
    }
    return 0;
}
