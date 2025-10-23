#include <stdio.h>

#define N 2

// Function to multiply two matrices
void multiply(int A[N][N], int B[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to print matrix
void printMatrix(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int A[N][N] = {{2, 1}, {2, 0}};
    int M[N][N] = {{3, 1}, {2, 0}};
    int Nmat[N][N] = {{1, 0}, {-1, 1}};
    int E[N][N] = {{1, 2}, {0, 1}};  // elementary matrix

    int AE[N][N], NE[N][N], MNE[N][N];

    // Compute AE and NE
    multiply(A, E, AE);
    multiply(Nmat, E, NE);

    // Compute M * (NE)
    multiply(M, NE, MNE);

    printf("AE = \n");
    printMatrix(AE);

    printf("NE = \n");
    printMatrix(NE);

    printf("M * NE = \n");
    printMatrix(MNE);

    return 0;
}
