#include <bits/stdc++.h>

using namespace std;
double fx(double x) {
    double y = x * 0.225035;

    return 1.2 * x - 0.6 * x * y;
}

double fy(double y) {
    double x = y * 2;

    return -0.8 * y + 0.3 * x * y;
}

int main() {
    for (int i = -15; i < 16; i++) {
        cout << fy(i) << " " << endl;
    }
}
