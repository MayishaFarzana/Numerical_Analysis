#include<bits/stdc++.h>
using namespace std;

int ar[100];
int br[100];
int n;
int aprime[100];
int nprime;

double f(double x)
{
    double res = ar[n];
    for (int i = n - 1; i >= 0; i--)
    {
        res = res * x + ar[i];
    }
    return res;
}
double fprime(double x)
{
    for (int i = n; i > 0; i--)
    {
        aprime[i - 1] = ar[i] * i;
    }

    nprime = n - 1;
    double res = aprime[nprime];
    for (int i = nprime - 1; i >= 0; i--)
    {
        res = res * x + aprime[i];
    }
    return res;
}

int main()
{
    double ERROR = 0.001;
    cout << "Enter the degree of the equation : ";
    cin >> n;
    cout << "Enter the coefficients of the equation:" << endl;
    for (int i = 0; i <= n; i++)
    {
        cin >> ar[i];
    }
    double x0, xr;
    cout << "Enter the value of x0 :";
    cin >> x0;
    int rc = 1;
    while (n > 0)
    {
        while (true)
        {
            xr = x0 - (f(x0) / fprime(x0));
            double err = fabs((xr - x0) / xr);
            if (err <= ERROR)
            {
                cout << "Root no. "  << rc++ << "\t" << xr << endl;
                break;
            }
            x0 = xr;
        }
        br[n] = 0;
        for (int i = n; i > 0; i--)
        {
            br[i - 1] = ar[i] + xr * br[i];
        }
        n--;
        for (int i = 0; i <= n; i++)
            ar[i] = br[i];
        x0 = xr;
    }

    return 0;
}

