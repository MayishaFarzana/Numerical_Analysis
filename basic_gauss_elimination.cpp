#include<bits/stdc++.h>
using namespace std;

int n;
double ar[100][100];
double roots[100];

int main()
{
    cout << "Enter the number of equations : ";
    cin >> n;
    cout << "Enter the coefficents of equations \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> ar[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        double x = ar[i][i];
        for (int j = 0; j < n + 1; j++)
        {
            ar[i][j] = ar[i][j] / x;
        }

        for (int j = i + 1; j < n; j++)//j=i+1 change in here if 9i==j) continue is not incluse here
        {
            int x = ar[j][i];
            for (int k = 0; k < n + 1; k++)
            {
                ar[j][k] = ar[j][k] - ar[i][k] * x;
            }
        }
    }

    double root = ar[n - 1][n] / ar[n - 1][n - 1];//n=3
    roots[n - 1] = root;//root[2]

    for (int i = n - 2; i >= 0; i--)//i=1 0
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)//j=2 1st loop  1 2 2nd loop
        {
            sum += ar[i][j] * roots[j];
        }
        roots[i] = (ar[i][n] - sum) / ar[i][i];//root[1];;root[0]
    }

    for (int i = 0; i < n; i++)
        cout << roots[i] << " ";
    cout << endl;

    return 0;
}
