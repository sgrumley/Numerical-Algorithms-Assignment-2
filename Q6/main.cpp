#include <bits/stdc++.h>

using namespace std;


double f1(double x) {
    return 1.0 / (1.0 + (x * x));
}

double f2(double x)  {
    return 0.8 + 5.0 * x - (100.0 * pow(x, 2)) + 75.0 * pow(x, 3) + 100.0 * pow(x, 5);
}

double f(double x) {
    return pow(x, 0.1) * (1.2 - x) * (1.0 - exp(20.0 * (x - 1.0)));
}

// Gauss Quadrature method, takes in n for n-points
double gaussQuadrature(int points, double a, double b)  {
    double m = (b - a) / 2;
    double n = (b + a) / 2;
    double r = 0.0;

    double x[5][6] = {
        { -0.577350269, 0.577350269,  0.0,           0.0,           0.0,           0.0             },
        { -0.774596669, 0.000000000,  0.774596669,   0.0,           0.0,           0.0             },
        { -0.861136312, -0.339981044, 0.339981044,   0.861136312,   0.0,           0.0             },
        { -0.906179846, -0.538469310, 0.000000000,   0.538469310,   0.906179846,   0.0             },
        { -0.932469514, -0.661209386, -0.2386191860, 0.2386191860,  0.661209386,   0.932469514     }
    };
    double c[5][6] = {
        {  1.000000000, 1.000000000,  0.0,          0.0,          0.0,          0.0          },
        { 0.555555556,  0.888888889,  0.555555556,  0.0,          0.0,          0.0          },
        {  0.347854845, 0.652145155,  0.652145155,  0.347854845,  0.0,          0.0          },
        { 0.236926885,  0.478628670,  0.568888889,  0.478628670,  0.236926885,  0.0          },
        { 0.171324492,  0.360761573,  0.467913935,  0.467913935,  0.360761573,  0.171324492  }
    };

    for (int i = 0; i < points; i++) {
        // cout << i << " " << points - 2 <<  " " << c[points - 2][i] << " " << x[points - 2][i] << endl;
        r += c[points - 2][i] * f(m * x[points - 2][i] + n);
    }
    r *= m;
    return r;
}

int main() {
    double res;

    // cout << "Part A:" << endl;

    // for (int i = 2; i <= 6; i++) {
    //     res = gaussQuadrature(i, -3.0, 3.0);
    //     cout << "Point: " << i << " Integral: " << res << endl;
    // }

    // cout << "Part B:" << endl;

    // for (int i = 2; i <= 6; i++) {
    //     res = gaussQuadrature(i, 2.0, 8.0);
    //     cout << "Point: " << i << " Integral: " << res << endl;
    // }

    cout << "Part C:" << endl;

    for (int i = 2; i <= 6; i++) {
        res = gaussQuadrature(i, 1.0, 5.0);
        cout << "Point: " << i << " Integral: " << res << endl;
    }
}
