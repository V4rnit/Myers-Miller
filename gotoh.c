#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 10000
int getMin2(int a, int b){
    return (a < b) ? a : b;
}

int getMin3(int a, int b, int c){
    int min = a;
    if(b < a) min = b;
    return(min < c) ? min : c;
}
// GA = gap in A
// GB = gap in B

int gotoh(char* A, char* B, int gapOpen, int gapExtend, int misMatch){
    int m = strlen(A);
    int n = strlen(B);

    int C[m + 1][n + 1];
    int GA[m + 1][n + 1];
    int GB[m + 1][n + 1];

    C[0][0] = 0;
    GA[0][0] = INF;
    GB[0][0] = INF;

    // First column: B is empty, so gaps are in B
    for(int i = 1; i <= m; i++){
        if(i == 1){
            C[i][0] = gapOpen;
        }
        else{
            C[i][0] = C[i - 1][0] + gapExtend;
        }

        GA[i][0] = INF;
        GB[i][0] = C[i][0];
    }

    // First row: A is empty, so gaps are in A
    for(int j = 1; j <= n; j++){
        if(j == 1){
            C[0][j] = gapOpen;
        }
        else{
            C[0][j] = C[0][j - 1] + gapExtend;
        }

        GA[0][j] = C[0][j];
        GB[0][j] = INF;
    }

    // Fill the matrices
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){

            // Gap in A -> move left
            GA[i][j] = getMin2(
                GA[i][j - 1] + gapExtend,
                C[i][j - 1] + gapOpen
            );

            // Gap in B -> move up
            GB[i][j] = getMin2(
                GB[i - 1][j] + gapExtend,
                C[i - 1][j] + gapOpen
            );

            // Match / mismatch -> move diagonal
            int diagonal;

            if(A[i - 1] == B[j - 1]){
                diagonal = C[i - 1][j - 1];
            }
            else{
                diagonal = C[i - 1][j - 1] + misMatch;
            }

            // Best way to reach this cell
            C[i][j] = getMin3(
                diagonal,
                GA[i][j],
                GB[i][j]
            );
        }
    }

    return C[m][n];
}


int main(){
    char A [] = "ABC";
    char B [] = "ADC";
    int gapOpen = 0;
    int gapExtend = 0;
    int misMatch = 0;
    scanf("%d %d %d", &gapOpen, &gapExtend, &misMatch);
    printf("\n");
    printf("%d", gotoh(A, B, gapOpen, gapExtend, misMatch));
    printf("\n");
    return 0;
}