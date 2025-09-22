#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // For fabs()

int main() {
    // Plane: 3x + 5y + 4z = 11
    double n[] = {3, 5, 4};  // Normal vector components
    double d_plane = 11;     // Plane constant
    double distance = 2 * sqrt(2); // Given distance

    // Point: (2, 1, lambda)
    double x = 2, y = 1;
    double lambda;

    // Distance formula: d = |n . p - d_plane| / ||n||
    // ||n|| = sqrt(3^2 + 5^2 + 4^2) = sqrt(50) = 5*sqrt(2)
    double norm_n = sqrt(n[0]*n[0] + n[1]*n[1] + n[2]*n[2]); 

    // Solve for lambda: |n . p - d_plane| / ||n|| = distance
    // n . p = 3*2 + 5*1 + 4*lambda = 11 + 4*lambda
    // |11 + 4*lambda - 11| / (5*sqrt(2)) = 2*sqrt(2)
    // => |4*lambda| / (5*sqrt(2)) = 2*sqrt(2)
    // => |lambda| = 5
    lambda = 5;
    printf("Lambda = %.2f or %.2f\n", lambda, -lambda);

    return 0;
}
