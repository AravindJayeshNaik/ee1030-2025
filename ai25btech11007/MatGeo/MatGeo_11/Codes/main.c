#include <stdio.h>

int main() {
    double A[3][4]; // augmented matrix [3x4]
    double k;

    // Input value of k
    printf("Enter the value of k: ");
    scanf("%lf", &k);

    // Initialize augmented matrix
    A[0][0] = 1; A[0][1] = 1;  A[0][2] = 1;  A[0][3] = 2;
    A[1][0] = 2; A[1][1] = 1;  A[1][2] = -1; A[1][3] = 3;
    A[2][0] = 3; A[2][1] = 2;  A[2][2] = k;  A[2][3] = 4;

    // Row reduction: R2 = R2 - 2*R1
    for(int j=0; j<4; j++)
        A[1][j] -= 2*A[0][j];

    // Row reduction: R3 = R3 - 3*R1
    for(int j=0; j<4; j++)
        A[2][j] -= 3*A[0][j];

    // Row reduction: R3 = R3 - R2
    for(int j=0; j<4; j++)
        A[2][j] -= A[1][j];

    // Check k for uniqueness
    if (A[2][2] != 0) {
        printf("The system has a unique solution.\n");

        // Back-substitution to solve
        double z = A[2][3] / A[2][2];
        double y = (A[1][3] - A[1][2]*z) / A[1][1];
        double x = A[0][3] - A[0][1]*y - A[0][2]*z;

        printf("Solution: x = %.2lf, y = %.2lf, z = %.2lf\n", x, y, z);
    } else {
        // If k = 0 or row reduces to 0
        printf("The system has no solution (inconsistent).\n");
    }

    return 0;
}
