//(bisection modified)
#include<bits/stdc++.h>
using namespace std;

int ar[100];
int n;

double f(double x)
{
    double res = ar[n];
    for (int i = n - 1; i >= 0; i--)
    {
        res = res * x + ar[i];
    }
    return res;
}

int main()
{
    double ERROR = 0.0001;

    cout << "Enter the degree of the equation : ";
    cin >> n;
    cout << "Enter the coefficients (From maximum power) :" << endl;
    for (int i = n; i >= 0; i--)
    {
        cin >> ar[i];
    }

    double a, b;
    cout << "Choose lower limit a and upper limit b covering all the roots: ";
    cin >> a >> b;
    //Decide the size of the increment interval Delta X
    double dx = 0.1;
    double x1, x2;

    int itr = 0;

    cout << "\t\t\t" << "x0\t" << "x1\t" << "x2\t" <<  "f0\t" << "f1\t" << "f2\t" << "Error" << endl;

    while (true)
    {
        x1 = a, x2 = x1 + dx;

        double f1 = f(x1), f2 = f(x2);

        if (f1 * f2 <= 0)
        {
            while (true)
            {
                cout << "Iteration ";
                printf("%10d: ", ++itr);

                double x0 = (x1 + x2) / 2;
                double f0 = f(x0);

                printf("%.4f\t", x0);
                printf("%.4f\t", x1);
                printf("%.4f\t", x2);
                printf("%.4f\t", f0);
                printf("%.4f\t", f1);
                printf("%.4f\t", f2);
                printf("%.4f\n", fabs((x2- x1)/x2));

                if (f1 * f0 < 0)
                {
                    x2 = x0;
                }
                else
                {
                    x1 = x0;
                }
                if (fabs((x2- x1)/x2) < ERROR)
                {
                    double root = (x1 + x2) / 2;
                    cout << "\nBetween "<< x1 << " and " << x2 << " there is a root " << root << endl << endl;
                    break;
                }
            }
        }
        if (x2 < b)
        {
            a = a + dx;
        }
        else
        {
            break;
        }
    }

    return 0;
}
