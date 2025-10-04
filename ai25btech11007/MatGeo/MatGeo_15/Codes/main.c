#include <stdio.h>
#include <math.h>

int main() {
    // Define vectors and constants
    double F[2] = {-1, 2};      // Focus
    double n[2] = {1, -2};      // Normal vector to directrix
    double c = -3;              // Constant term from directrix n^T x = c
    double e = 1;               // Parabola => e = 1

    // Compute ||n||^2
    double norm_n2 = n[0]*n[0] + n[1]*n[1];

    // Identity matrix I
    double I[2][2] = {{1, 0}, {0, 1}};

    // Compute n*n^T
    double nnT[2][2];
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            nnT[i][j] = n[i]*n[j];

    // Compute V = ||n||^2 * I - e^2 * (n*n^T)
    double V[2][2];
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            V[i][j] = norm_n2*I[i][j] - e*e*nnT[i][j];

    // Compute u = c*e^2*n - ||n||^2 * F
    double u[2];
    for(int i=0; i<2; i++)
        u[i] = c*e*e*n[i] - norm_n2*F[i];

    // Compute f = ||n||^2 * ||F||^2 - c^2 * e^2
    double f = norm_n2 * (F[0]*F[0] + F[1]*F[1]) - (c*c*e*e);

    // Display results
    printf("Matrix Form of Parabola:\n\n");

    printf("V = [ [%.2f, %.2f], [%.2f, %.2f] ]\n",
           V[0][0], V[0][1], V[1][0], V[1][1]);

    printf("u = [ %.2f, %.2f ]^T\n", u[0], u[1]);
    printf("f = %.2f\n\n", f);

    printf("Conic Equation: x^T V x + 2u^T x + f = 0\n");
    printf("=> [x y] [%.2f %.2f; %.2f %.2f] [x; y] + 2[%.2f %.2f][x; y] + %.2f = 0\n",
           V[0][0], V[0][1], V[1][0], V[1][1], u[0], u[1], f);

    return 0;
}
