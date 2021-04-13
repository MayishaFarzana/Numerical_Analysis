// NEWTON RAPHSON METHOD
#include<bits/stdc++.h>
using namespace std;
int ar[100];
int n;
double f(double x)    // Using using Horner's method
{
    double res = ar[n];
    for (int i = n - 1; i >= 0; i--){
        res = res * x + ar[i];
    }
    return res;
}

double fprime(double x)
{
    return 2*x-4;
}

int main() {
    double ERROR = 0.001;
    cout << "Enter the degree of the equation : ";
    cin >> n;

    for (int i = n; i >= 0; i--)
    {
        cout << "Enter the value of a" << i << " " << endl;
        cin >> ar[i];
    }

    cout << "Enter the value of x0 :";
    double x0, x1;
    cin >> x0;
   cout <<setprecision(4)<< "\t\t\t x0 \t x1  \t   f0 \t  f1\t ERROR\n\n";

    int itr = 0;
    while (true)
    {
         printf("Iteration %10d : ", ++itr);
        x1 = x0 - (f(x0) / fprime(x0));

         cout << x0 << " \t" << x1 <<" \t ";
          if (f(x0) >= 0)
            cout << "+" << " \t ";
        else
            cout << "-" << " \t ";
        if (f(x1) >= 0)
            cout << "+" << " \t ";
        else
            cout << "-" << "\t";

        double err = fabs((x1 - x0) / x1);
        cout<<err<<endl;
        if (err <= ERROR)
        {
            cout << "\nThe root is " << x1 << endl;
            break;
        }
        x0 = x1;
    }
    return 0;
}
