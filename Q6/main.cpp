#include <bits/stdc++.h>

using namespace std;


double f(double x)  {
    return pow(x, 5) + pow(x, 3) + 3;
}

double f2(double x) {}

// Gauss Quadrature method, takes in n for n-points
double gaussQuadrature(int points, double a, double b, double x[][6], double c[][6])  {
    double m = (b - a) / 2;
    double n = (b + a) / 2;
    double r = 0.0;

    for (int i = 0; i < points; i++) {
        r += c[points][i] * f(m * x[points][i] + n);
    }
    r *= m;
    return r;
}

int main() {
    // Q
}
