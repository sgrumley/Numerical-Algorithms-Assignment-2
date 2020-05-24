#include <bits/stdc++.h>

using namespace std;

int LU()
{
    int n, i, k, j, p;
    double l[10][10] = { 0 }, u[10][10] = { 0 }, sum,  z[10] = { 0 }, x[10] = { 0 };

    double a[4][4] = {
        { 0, 0,   0,   0   },
        { 0, 25,  5,   1   },
        { 0, 64,  8,   1   },
        { 0, 144, 12,  1   }
    };

    double b[4] = {
        0,
        106.8,
        177.2,
        279.2
    };

    n = 3;

    for (k = 1; k <= n; k++) {
        u[k][k] = 1;

        for (i = k; i <= n; i++) {
            sum = 0;

            for (p = 1; p <= k - 1; p++) {
                sum += l[i][p] * u[p][k];
            }
            l[i][k] = a[i][k] - sum;
        }

        for (j = k + 1; j <= n; j++) {
            sum = 0;

            for (p = 1; p <= k - 1; p++) {
                sum += l[k][p] * u[p][j];
            }
            u[k][j] = (a[k][j] - sum) / l[k][k];
        }
    }

    cout << endl << endl << "LU matrix is " << endl;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) cout << l[i][j] << "  ";
        cout << endl;
    }
    cout << endl;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) cout << u[i][j] << "  ";
        cout << endl;
    }

    for (i = 1; i <= n; i++) {
        sum = 0;

        for (p = 1; p < i; p++) {
            sum += l[i][p] * z[p];
        }
        z[i] = (b[i] - sum) / l[i][i];
    }

    for (i = n; i > 0; i--) {
        sum = 0;

        for (p = n; p > i; p--) {
            sum += u[i][p] * x[p];
        }
        x[i] = (z[i] - sum) / u[i][i];
    }

    // *********** DISPLAYING SOLUTION**************//
    cout << endl << "Set of solution is" << endl;

    for (i = 1; i <= n; i++) {
        cout << endl << x[i];
    }

    return 0;
}

int main() {
    // Q
    LU();
}

// // convert to upper triangular form
// for (int k = 0; k < n - 1; k++) {
//     try {
//         for (int i = k + 1; i < n; i++) {
//             float s = a[i, k] / a[k, k];

//             for (int j = k; j < n; j++) {
//                 a[i, j] -= a[k, j] * s;
//             }
//             b[i] = b[i] - b[k] * s;
//         }
//     }
//     catch (DivideByZeroException e) {
//         cout << e.Message << endl;
//     }
// }

// // back substitution
// b[n - 1] = b[n - 1] / a[n - 1, n - 1];

// for (int i = n - 2; i >= 0; i--) {
//     sum = b[i];

//     for (int j = i + 1; j < n; j++) {
//         sum -= a[i, j] * b[j];
//     }
//     b[i] = sum / a[i, i];
// }
