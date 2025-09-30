#include <stdio.h>

int main() {
    // Augmented matrix for the system
    // lambda - 2*mu = 3
    // 2*lambda - mu = 3
    // -lambda - mu = 0
    double a[3][3] = {
        {1, -2, 3},
        {2, -1, 3},
        {-1, -1, 0}
    };

    int n = 2; // number of unknowns: lambda and mu
    double x[2]; // solution array

    // Gaussian elimination
    for(int i=0; i<n; i++) {
        // Make the diagonal element 1
        double diag = a[i][i];
        for(int j=i; j<=n; j++) {
            a[i][j] /= diag;
        }

        // Eliminate the current variable from rows below
        for(int k=i+1; k<n; k++) {
            double factor = a[k][i];
            for(int j=i; j<=n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Back substitution
    for(int i=n-1; i>=0; i--) {
        x[i] = a[i][n];
        for(int j=i+1; j<n; j++) {
            x[i] -= a[i][j] * x[j];
        }
    }

    double lambda = x[0];
    double mu = x[1];

    printf("Solution:\n");
    printf("lambda = %.2lf\n", lambda);
    printf("mu = %.2lf\n", mu);

    // Intersection point
    double r[3];
    r[0] = lambda * 1;      // lambda * (1)
    r[1] = lambda * 2;      // lambda * (2)
    r[2] = lambda * (-1);   // lambda * (-1)

    printf("Intersection Point: (%.2lf, %.2lf, %.2lf)\n", r[0], r[1], r[2]);
    printf("Shortest Distance = 0 units (lines intersect)\n");

    return 0;
}
