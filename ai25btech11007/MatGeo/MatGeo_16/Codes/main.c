#include <stdio.h>
#include <math.h>

// Function for the parabola y = 3*sqrt(x)
double parabola(double x) {
    return 3 * sqrt(x);
}

// Function for the line y = 3*x
double line(double x) {
    return 3 * x;
}

// Function to compute area using trapezoidal rule
double area_between_curves(double a, double b, int n) {
    double h = (b - a) / n;
    double area = 0.0;
    for(int i = 0; i <= n; i++) {
        double x = a + i*h;
        double y_diff = parabola(x) - line(x);
        if(i == 0 || i == n)
            area += y_diff / 2.0;
        else
            area += y_diff;
    }
    area *= h;
    return area;
}

int main() {
    double a = 0.0, b = 1.0; // limits of integration (intersection points)
    int n = 1000; // number of subintervals for numerical integration

    double area = area_between_curves(a, b, n);
    printf("Area enclosed between y^2 = 9x and y = 3x: %.6f square units\n", area);

    // Direct symbolic calculation
    double symbolic_area = 3.0*(2.0/3.0 - 0.5);
    printf("Area calculated symbolically: %.6f square units\n", symbolic_area);

    return 0;
}
