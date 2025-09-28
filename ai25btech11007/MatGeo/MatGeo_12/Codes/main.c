#include <stdio.h>

int main() {
    // Inverse of A
    double Ainv[3][3] = {
        {1, -1, 0},
        {-2, 3, -4},
        {-2, 3, -3}
    };

    // Vector b
    double b[3] = {21, 20, 5};

    // Result vector x = Ainv * b
    double x[3] = {0, 0, 0};

    // Matrix-vector multiplication
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            x[i] += Ainv[i][j] * b[j];
        }
    }

    // Print the solution
    printf("Solution of the system:\n");
    printf("x = %.2lf\n", x[0]);
    printf("y = %.2lf\n", x[1]);
    printf("z = %.2lf\n", x[2]);

    return 0;
}
