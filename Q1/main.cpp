#include <bits/stdc++.h>
#define PI 3.14159265

using namespace std;

double f(double x) {
    double part = x - (x * x) / 10;

    return 2 * sin(x) - (x * x) / 10;
}

double paraStep(double a, double fa, double b, double fb, double c, double fc) {
    double xTopSub  = (b - a) * (f(b) - f(c));
    double xTopSub1 = (b - c) * (f(b) - f(a));
    double xTop     = (b - c) * xTopSub1 - (b - a) * xTopSub;
    double xBot     = 2.0 * (xTopSub - xTopSub1);

    // double xTop =  pow((b - a), 2) * (f(b) - f(c)) - pow((b - c), 2) * (f(b) - f(a));
    // double xBot = (b - a) * (f(b) - f(c)) - (b - c) * (f(b) - f(a));

    return b - 0.5 * (xTop / xBot);
}

void PIMax(double a, double b) {
    double es = 0.001;
    double err;

    double xTopSub, xTopSub1, xTop, xBot, d;

    double c    = (a + b) / 2;
    double dOld = 1;

    double fa = f(a);
    double fb = f(b);
    double fc = f(c);

    for (int i = 1; i <= 9999; i++) {
        if (abs(b - a) < es) {
            cout << "After " << i << " iterations the root is: " << d << endl;
            return;
        }

        d = paraStep(a, fa, b, fb, c, fc);

        if (abs(dOld - d) < es) {
            cout << "After " << i << " iterations the root is: " << f(d) << " at " << d << endl;
            return;
        }

        if (abs(f(dOld) - f(d)) < es) {
            cout << "Afterfunc " << i << " iterations the root is: " << f(d) << " at x=" << d << endl;
            return;
        }

        dOld = d;

        // use d and f(d) to reduce bracating interval
        if (d < b) {
            if (f(d) < f(b)) {
                // d is in the higher sub interval, discard lower interval
                a = a;
                b = d;
                c = b;
            } else if (f(d) > f(b)) {
                // d is in the lower sub interval, discard higher interval
                a = d;
                b = b;
                c = c;
            }
        } else if (d > b) {
            if (f(d) < f(b)) {
                // d is in the upper sub interval, discard lower interval
                a = b;
                b = d;
                c = c;
            } else if (f(d) > f(b)) {
                // d is in the lower sub interval, discard higher interval
                a = a;
                b = b;
                c = d;
            }
        }


        // // err = fabs((xu - xl) / fxopt) * 100;
        cout << "a " << a << " b " << b << " c " << c << " x " << d <<  endl;
        cout << "fa " << f(a) << " fb " << f(b) << " fc " << f(c) << " fx " << f(d) <<  endl << endl;

        if (i == 20) {
            cout << "Max " << b;
            return;
        }
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

// void getem(double ea, double x1, double x3) {
//     double x2 = (x1 + x3) / 2;

//     if ((f(x2) > f(x3)) && (f(x2) > f(x1))) {
//         cout << "max found end";
//     }

//     double fval_old = min(min(f(x1), f(x2)), min(f(x3), f(x2)));
//     double tol = 1;
//     double xmin, foal, fval, x4;

//     for (int i = 1; i <= 20; i++) {
//         x4 = paraStep(x1, f(x1), x2, f(x2), x3, f(x3)); // x2 - 0.5 * (pow((x2 - x1), 2)  * (f(x2) - f(x3)) - pow((x2 - x3), 2)  * (f(x2) - f(x1))) / ((x2 - x1) * (f(x2) - f(x3)) - (x2 - x3) *
// (f(x2)
//                                                         // - f(x1)));
//         cout << "x" << x4 << endl;
//         cout << "a " << x1 << " b " << x2 << " c " << x3 << " x "  <<  endl;

//         if ((f(x4) < f(x1)) && (f(x4) < f(x2))) {
//             x3   = x2;
//             x2   = x4;
//             xmin = x4;
//             foal = f(x4);
//         }

//         else {
//             x1   = x2;
//             x2   = x4;
//             xmin = x4;
//             fval = f(x4);
//         }

//         tol = abs((fval - fval_old) / (fval));
//         double Ival_old = fval;


//         cout << fval << " " << foal << endl;
//     }
// }
