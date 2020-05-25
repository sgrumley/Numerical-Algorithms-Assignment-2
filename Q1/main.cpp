#include <bits/stdc++.h>

using namespace std;

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

void PIMax(double a, double b) {
    double es = 0.0001;
    double err;

    double xTopSub, xTopSub1, xTop, xBot, d;

    double c    = (a + b) / 2;
    double dOld = 1;

    double fa = f(a);
    double fb = f(b);
    double fc = f(c);

    for (int i = 1; i <= 9999; i++) {
        d = paraOpt(a, fa, b, fb, c, fc);

        if ((abs(dOld - d) < es) || (abs(f(dOld) - f(d)) < es)) {
            cout << "After " << i << " iterations the maximum value is: " << f(d) << " at x = " << d << endl;
            return;
        }

        dOld = d;

        // use d and f(d) to reduce bracating interval
        if (d > b) {
            if (f(d) > f(b)) {
                // d is in the higher sub interval, discard lower interval
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
    }
    cout << "Max a" << b;
}

//

int main() {
    double a = 1.0;
    double b = 3.0;

    PIMax(a, b);

    cout << endl << f(1.4276);
}
