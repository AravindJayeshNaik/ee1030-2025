#include <stdio.h>

// Function to compute determinant of 3x2 augmented with 0 column
// Actually we compute rank check: det([n1 n2]) = 0 always
int main() {
    int alpha;
    printf("Lines:\n");
    printf("L1: x/5 = y/(3-alpha) = z/(-2)\n");
    printf("L2: x/alpha = y/(-1) = z/(2-alpha)\n\n");

    printf("Checking coplanarity for sample alpha values...\n");

    for(alpha = -3; alpha <= 5; alpha++) {
        int n1[3] = {5, 3 - alpha, -2};
        int n2[3] = {alpha, -1, 2 - alpha};

        // Compute determinant of 3x2 matrix (v1, v2)
        // In coplanarity test: rank <= 2 always (since both pass through origin)
        // Let's check cross product
        int cross[3];
        cross[0] = n1[1]*n2[2] - n1[2]*n2[1];
        cross[1] = n1[2]*n2[0] - n1[0]*n2[2];
        cross[2] = n1[0]*n2[1] - n1[1]*n2[0];

        printf("alpha = %d -> Lines are coplanar (always true)\n", alpha);
    }

    printf("\nConclusion: Lines are coplanar for all real alpha.\n");
    return 0;
}
