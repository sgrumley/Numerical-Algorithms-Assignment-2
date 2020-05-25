#include <bits/stdc++.h>


using namespace std;

double errorFunction(double total, double current) {
    return (total * current / total) * 100;
}

double f(double x) {
    return 2 * sin(x) - ((x * x) / 10);
}

double paraOpt(double a, double fa, double b, double fb, double c, double fc) {
    double xTopSub  = (b - a) * (f(b) - f(c));
    double xTopSub1 = (b - c) * (f(b) - f(a));
    double xTop     = (b - c) * xTopSub1 - (b - a) * xTopSub;
    double xBot     = 2.0 * (xTopSub - xTopSub1);

    return b + 0.5 * (xTop / xBot);
}

double calcD(double xl, double xu) {
    return (sqrt(5) - 1) / 2;
}

void brentsMethod(double a, double b) {
    double c    = (a + b) / 2;
    double dOld = 1;
    double es   = 0.0001;
    double fa   = f(a);
    double fb   = f(b);
    double fc   = f(c);
    double d;

    for (int i = 1; i <= 9999; i++) {
        // d is the current estimate for the optimum point
        d = paraOpt(a, fa, b, fb, c, fc);

        if ((f(a) < f(d)) && (f(d) > f(b))) {
            // && (abs(d - b) >= (abs(b - c) * 0.5)) && (abs(d - b) >= abs(c - d) * 0.5)
            // All conditions satisfied
            // use d and f(d) to reduce bracating interval
            cout << endl << "Parabolic Interpolation used:"  << endl;
        } else {
            // use golden section
            double h = b - a;

            if (f(a) > f(b)) {
                // /double h = b - a;
                d =  d + calcD(a, b) * h;
            } else {
                d = d - calcD(a, b) * h;
            }
            cout << endl << "Golden Section Used:"  << endl;
        }

        if (d > b) {
            if (f(d) > f(b)) {
                a = a;
                b = d;
                c = b;
            } else if (f(d) < f(b)) {
                // d is in the lower sub interval, discard higher interval
                a = d;
                b = b;
                c = c;
            }
        } else if (d < b) {
            if (f(d) > f(b)) {
                // d is in the upper sub interval, discard lower interval
                a = b;
                b = d;
                c = c;
            } else if (f(d) < f(b)) {
                // d is in the lower sub interval, discard higher interval
                a = a;
                b = b;
                c = d;
            }
        }
        cout << "a " << a << " b " << b << " c " << c << " x " << d <<  endl;
        cout << "fa " << f(a) << " fb " << f(b) << " fc " << f(c) << " fx " << f(d) <<  endl << endl;

        if ((abs(dOld - d) < es) || (abs(f(dOld) - f(d)) < es)) {
            cout << "After " << i << " iterations the maximum value is: " << f(d) << " at x = " << d << endl;
            return;
        }

        dOld = d;
    }
}

int main() {
    double a = 1.0;
    double b = 3.0;

    brentsMethod(a, b);
}
