#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 100000

int getMin2(int a, int b){
    return (a < b) ? a : b;
}
int getMin3(int a, int b, int c){
    int min = a;
    if(b < min){
        min = b;
    }
    return (min < c) ? min : c;
}

int gotohLinear(char* A, char* B, int gapOpen, int gapExtend, int misMatch){
    int m = strlen(A);
    int n = strlen(B);

    //Optimal alignment so far
    int C_curr [n + 1];
    int C_prev [n + 1];

    //Track just the Gap in sequence A
    int GA_curr[n + 1];
    int GA_prev[n + 1];

    //Track just the Gap in sequence B
    int GB_curr[n + 1];
    int GB_prev[n + 1];

    C_prev[0] = 0;
    GA_prev[0] = INF;
    GB_prev[0] = INF;

}