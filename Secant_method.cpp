// SECANT METHOD

#include<bits/stdc++.h>
using namespace std;

int ar[100];
int n;

double f(double x) {  // Using using Horner's method
    double res = ar[n];
    for (int i = n - 1; i >= 0; i--) {
        res = res * x + ar[i];
    }
    return res;
}


int main() {
    double ERROR = 0.001;

    cout << "Enter the degree of the equation : ";
    cin >> n;

    for (int i = n; i >= 0; i--) {
        cout << "Enter the value of a" << i << " " << endl;
        cin >> ar[i];
    }

    double x1, x2, x3;

    cout << "Enter the value of x1 and x2 : ";
    cin >> x1 >> x2;

    while (true) {
        double f1, f2;
        f1 = f(x1);
        f2 = f(x2);

        x3 = ((f2 * x1) - (f1 * x2)) / (f2 - f1);
        double err = fabs((x3 - x2) / x3);
        if (err <= ERROR)
        {
            cout << "The root is " << x3 << endl;
            break;
        }
        x1 = x2;
        x2 = x3;
    }

    return 0;
}
