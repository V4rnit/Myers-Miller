#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 10000

int getMin(int a, int b, int c){
    int min = a;
    if(b < a) min = b;
    return(min < c) ? min : c;
}
int replace(char a, char b, int mismatchCost){

    if(a == b) return 0;
    return mismatchCost;
}
int gotoh(char* A, char* B, int gapOpen, int gapExtend){
    int m = strlen(A);
    int n = strlen(B);

    int C [m + 1][n + 1];
    int GA [m + 1][n + 1];
    int GB [m + 1][n + 1];

    C[0][0] = 0;
    C[0][1] = gapOpen;
    C[1][0] = gapOpen;
    GA[0][0] = INF;
    GB[0][0] = INF;

    for(int i = 2; i < m; i++){
        C[i][0] = C[i - 1][0] + gapExtend;
    }
    for(int j = 2; j < n; j++){
        C[0][j] = C[j - 1][0] + gapExtend;
    }
}