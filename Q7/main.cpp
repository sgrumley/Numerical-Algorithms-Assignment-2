#include <bits/stdc++.h>

using namespace std;

void LU(int n) {
    double l[10][10] = { 0 }, u[10][10] = { 0 }, sum,  z[10] = { 0 }, x[10] = { 0 };


    // b
    // double a[4][4] = {
    //     { 0, 0,  0,  0                  },
    //     { 0, 6,  0,  -1                 },
    //     { 0, 0,  3,  -1                 },
    //     { 0, 25, 12, -8                 }
    // };

    // double b[4] = {
    //     0,
    //     400,
    //     400,
    //     3600
    // };

    // a
    double a[4][4] = {
        { 0, 0,  0,   0                       },
        { 0, 2,  -6,  -1                      },
        { 0, -3, -1,  7                       },
        { 0, -8, 1,   -2                      }
    };

    double b[4] = {
        0,
        -38.0,
        -34.0,
        -20
    };


    // Make L U
    for (int i = 1; i <= n; i++) {
        u[i][i] = 1;

        // Upper triange
        for (int j = i; j <= n; j++) {
            sum = 0;

            for (int k = 1; k <= i - 1; k++) {
                sum += l[j][k] * u[k][i];
            }
            l[j][i] = a[j][i] - sum;
        }

        // Lower triangle
        for (int j = i + 1; j <= n; j++) {
            sum = 0;

            for (int k = 1; k <= i - 1; k++) {
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = (a[i][j] - sum) / l[i][i];
        }
        cout << endl;
    }


    cout << "L Matrix" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << l[i][j] << "  ";
        cout << endl;
    }

    cout << endl << "U Matrix" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << u[i][j] << "  ";
        cout << endl;
    }

    // Solve for Ax = b
    // Forward substitution - Lx = b
    for (int i = 1; i <= n; i++) {
        sum = 0;

        for (int j = 1; j < i; j++) {
            sum += l[i][j] * z[j];
        }
        z[i] = (b[i] - sum) / l[i][i];
    }

    // Backward substitution - Ux = b
    for (int i = n; i > 0; i--) {
        sum = 0;

        for (int j = n; j > i; j--) {
            sum += u[i][j] * x[j];
        }
        x[i] = (z[i] - sum) / u[i][i];
    }

    char pr[4] = { 'a', 'x', 'y', 'z' };
    cout << endl << "Resulting values: " << endl;

    for (int i = 1; i <= n; i++) {
        cout << pr[1] << i << " = " << x[i] << endl;
    }
}

int main() {
    // Q
    int n = 3;

    LU(n);
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
