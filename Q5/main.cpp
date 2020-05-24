#include <bits/stdc++.h>

using namespace std;

vector<double> xval;
vector<double> yval;

void dataDump() {
    ofstream myfile;

    myfile.open("dxdt.txt");
    myfile.open("dydt.txt");

    for (int i = 0; i < xval.size(); i++) {
        myfile << xval[i] << " " << yval[i] << endl;
    }

    myfile.close();
}

double dxdt(double x, double y) {
    double a = 1.2;
    double b = 0.6;

    return a * x - b * x * y;
}

double dydt(double x, double y) {
    double c = 0.8;
    double d = 0.3;

    return -c * y + d * x * y;
}

// Finds value of y for a given x using step size h
// and initial value y0 at x0.
double RK(double t0, double xy0, double t, double h) {
    // int n = (int)((t - t0) / h);
    int n = 30;

    double k1, k2, k3, k4, k5;
    double xy = xy0;

    for (int i = 1; i <= n; i++) {
        k1 = h * dxdt(t0, xy);
        k2 = h * dxdt(t0 + h / 2, xy +  k1 / 2);
        k3 = h * dxdt(t0 + h / 2, xy +  k2 / 2);
        k4 = h * dxdt(t0 + h, xy + k3);

        // Update x and y
        t0 = t0 + h;
        xy = xy  + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        cout << t0 << ", " << xy << endl;
    }

    return xy;
}

// Driver method
int main() {
    double t0 = 0, xy = 1, t = 2, h = 1.0;
    vector<double> xVal;
    vector<double> yVal;

    double res = RK(t0, xy, t, h);

    cout << res << endl;
}
