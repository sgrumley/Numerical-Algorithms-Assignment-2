#include <bits/stdc++.h>

using namespace std;

double f(double m) {
    double g = 9.8;
    double c = 15;
    double t = 9;
    double v = 35;
    double p = (c / m) * t;

    return g * m / c * (1 - exp(-p)) - v;
}

void falsePosition(double a, double b) {
    cout << "f(a) = " << f(a) << endl;
    cout << "f(b) = " << f(b) << endl;

    if (f(a) * f(b) >= 0) {
        cout << "incorrect guess\n";
        return;
    }

    // initialize result
    double c   = a;
    double err = 1;

    int n = 0;

    while (1) {
        // Find the point that touches x axis
        double cold = c;
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Check if the above found point is root
        if (f(c) == 0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        cout << c << " " << err << endl;
        err = (cold - c) / cold;

        if ((b - a) / pow(2, n + 1) <= 0.001) {
            cout << "The value of root is : " << c << endl << endl;
            return;
        }
        n++;
    }
}

double fb(double c) {
    // part b
    double g = 9.8;
    double m = 80;
    double t = 4;
    double v = 36;
    double p = (c / m) * t;

    return g * m / c * (1 - exp(-p)) - v;
}

void bisection(double a, double b) {
    double c;

    for (int n = 0; n < 15000; n++) {
        c = (a + b) / 2;

        if (fb(c) * fb(a) < 0) {
            // a, c new intervals
            b = c;
        } else {
            // b, c new intervals
            a = c;
        }

        if ((b - a) / pow(2, n + 1) <= 0.02) {
            cout << "Bisection: " << c << endl;
            return;
        }
    }
}

int main() {
    // Q
    double a = 30, b = 60;

    falsePosition(a, b);
    a = 3.0;
    b = 4.0;
    bisection(a, b);
}
