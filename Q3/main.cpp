#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    double y   = (4 * x) / (x - 4);
    double y2  = y * y;
    double x2  = x * x;
    double val = x2 + y2;

    return sqrt(val);
}

double calcD(double xl, double xu) {
    return fabs(xu - xl) * ((sqrt(5) - 1) / 2);
}

void GSS(double xl, double xu) {
    double es = 0.01;
    double err, xopt, fxopt, d;
    double x1 = xl + calcD(xl, xu);
    double x2 = xu - calcD(xl, xu);


    for (int i = 1; i <= 9999; i++) {
        d = calcD(xl, xu);


        if (f(x1) < f(x2)) {
            xopt  = f(x1);
            fxopt = x1;
            xl    = x2;
            x2    = x1;
            x1    = xl + calcD(xl, xu);
        } else if (f(x2) < f(x1)) {
            xopt  = f(x2);
            fxopt = x2;
            xu    = x1;
            x1    = x2;
            x2    = xu - calcD(xl, xu);
        }

        err = fabs((xu - xl) / fxopt) * (1 - ((sqrt(5) - 1) / 2)) * 100;
        cout << "iteration " << i << " d " << d << " xopt " << fxopt << " f(xopt) " << xopt << " error " << err << endl;


        if (err < es) {
            break;
        }
    }
    cout << "Minimum length of the ladder is " << xopt;
}

int main() {
    // Q3golden-section seacrch
    double xl = 5.0;
    double xu = 10.0;

    GSS(xl, xu);
}
