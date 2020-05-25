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

double RKy(double x0, double y0, double x, double h) {
    int n = (int)((x - x0) / h);

    // int n = 30;

    double k1, k2, k3, k4, k5;
    double y = y0;

    for (int i = 1; i <= n; i++) {
        k1 = h * dydt(x0, y);
        k2 = h * dydt(x0 + h / 2, y +  k1 / 2);
        k3 = h * dydt(x0 + h / 2, y +  k2 / 2);
        k4 = h * dydt(x0 + h, y + k3);

        // Update x and y
        x = x0 + h;
        y = y  + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        // cout << x << ", " << y << endl;
    }

    return y;
}

double RKx(double x0, double y0, double x, double h) {
    int n = (int)((x - x0) / h);

    // int n = 30;

    double k1, k2, k3, k4, k5;
    double y = y0;

    for (int i = 1; i <= n; i++) {
        k1 = h * dxdt(x0, y);
        k2 = h * dxdt(x0 + h / 2, y +  k1 / 2);
        k3 = h * dxdt(x0 + h / 2, y +  k2 / 2);
        k4 = h * dxdt(x0 + h, y + k3);

        // Update x and y
        x = x0 + h;
        y = y  + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        //     cout << x << ", " << y << endl;
    }

    return y;
}

int main() {
    double x0 = 0, y = 1, x = 2, h = 0.1;


    double yRes = RKy(x0, y, x, h);

    double xRes = RKx(x0, x, y, h);

    cout << "value of x at t " << xRes << endl;
    cout << "value of y at t " << yRes << endl;
}
