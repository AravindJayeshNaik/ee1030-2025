#include <stdio.h>

int main() {
    // Line 1: (8/3)x - 4y + 8 = 0
    float a = 8.0/3.0;
    float b = -4;

    // Intercepts of line 1
    float x1 = -8 / a;   // x-intercept
    float y1 = -8 / b;   // y-intercept

    // Line 2: 2x - 3y = 0
    // Intercepts of line 2
    float x2 = 3;
    float y2 = -2;

    printf("Line 1: (8/3)x - 4y + 8 = 0\n");
    printf("Intercepts: (%.1f, 0) and (0, %.1f)\n\n", x1, y1);

    printf("Line 2: 2x - 3y = 0\n");
    printf("Intercepts: (%.1f, 0) and (0, %.1f)\n", x2, y2);

    return 0;
}
