#include<bits/stdc++.h>
using namespace std;

int a[100];
int n;

double pp(double x, int t)
{
    double res = 1;
    for (int i = 0; i < t; i++){
        res = res * x;
    }
    return res;
}

double f(double x)
{
    double sum = 0;
    for (int i = 0; i <= n; i++){
        int t = (a[i] * pp(x, i));
        sum += t;
    }
    return sum;
}


int main() {
    cout << "Enter the highest degree: ";
    cin >> n;

    for (int i = 0; i <= n; i++){
        cout << "a" << i << " = \n";
        cin >> a[i];
    }
    double E = 0.000001;
    double x1;
    double x2;
    double f1;
    double f2;


    do
    {
        cin >> x1 >> x2;
        f1 = f(x1);
        f2 = f(x2);
    }
    while (f1 * f2 > 0);

    double x0;
    double f0;

    while (true)
    {
        x0 =x1-(f1*(x2-x1))/(f2-f1);//avg change hobe
        f0 = f(x0);
        if (f0 == 0)
        {
            cout << "The root is " << x0 << endl;
            break;
        }
        if (f1 * f0 < 0){
            x2 = x0;
        }
        else {
            x1 = x0;
        }

        if (fabs((x2 - x1) / x2) < E){
            cout << "The root is " << x0 << endl;
            break;
        }
    }

    return 0;
}
