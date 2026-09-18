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
    int* C_curr = malloc(sizeof(int) * (n + 1));
    int* C_prev = malloc(sizeof(int) * (n + 1));

    //Track just the Gap in sequence A
    int* GA_curr = malloc(sizeof(int) * (n + 1));
    int* GA_prev = malloc(sizeof(int) * (n + 1));

    //Track just the Gap in sequence B
    int* GB_curr = malloc(sizeof(int) * (n + 1));
    int* GB_prev = malloc(sizeof(int) * (n + 1));

    C_prev[0] = 0;
    GA_prev[0] = INF;
    GB_prev[0] = INF;

    for(int i = 1; i <=n;i++){
        if(i == 1){
            C_prev[i] = gapOpen;
        }
        else{
            C_prev[i] = C_prev[i - 1] + gapExtend;
        }

        GA_prev[i] = C_prev[i];
        GB_prev[i] = INF;
    }
    
    //1. Fill GA -> Gap in sequence A
    //2. Fill GB -> Gap in sequence B
    //3. Fill C -> Our optimal Matrix
    for(int i = 1; i <= m; i++){
        if(i == 1){
            C_curr[0] = gapOpen;
        }
        else{
            C_curr[0] = C_prev[0] + gapExtend;
        }
        GA_curr[0] = INF;
        GB_curr[0] = C_curr[0];

        for(int j = 1; j <= n; j++){
            //GA prev is not really needed as we only move left but for now i have to mentally map it 
            GA_curr[j] =  getMin2(GA_curr[j - 1] + gapExtend, C_curr[j - 1] + gapOpen);
            GB_curr[j] = getMin2(GB_prev[j] + gapExtend, C_prev[j] + gapOpen);
            if(A[i - 1] != B[j - 1]){
                C_curr[j] = getMin3(GA_curr[j], GB_curr[j], C_prev[j - 1] + misMatch);
            }
            else{
                C_curr[j] = getMin3(C_prev[j - 1], GA_curr[j], GB_curr[j]);
            }
        }
        int* temp = C_prev;
        C_prev = C_curr;
        C_curr = temp;
        
        temp = GA_prev;
        GA_prev = GA_curr;
        GA_curr = temp;

        temp = GB_prev;
        GB_prev = GB_curr;
        GB_curr = temp;
    }
    int res = C_prev[n];
    free(C_prev);
    free(C_curr);
    free(GA_prev);
    free(GA_curr);
    free(GB_prev);
    free(GB_curr);
    return res;
}

int main(){
    char A [] = "ACD";
    char B [] = "AD";

    int gapOpen = 5;
    int gapExtend = 1;
    int misMatch = 2;

    printf("%d", gotohLinear(A, B, gapOpen, gapExtend, misMatch));
    printf("\n");
    return 1;
}