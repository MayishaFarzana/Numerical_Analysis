#include<bits/stdc++.h>
using namespace std;

int n;
int ar[1000][1000];

void print()
{
    cout << endl;
    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (ar[i][j] != -1)
            {
                cout << ar[i][j] << "\t";
            }
            else
            {
                cout << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            ar[i][j] = -1;
        }
    }

    cin >> n;

    for (int i = 0; i < 2 * n; i += 2)
    {
        cin >> ar[i][0] >> ar[i][1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j < 2 * n - i; j += 2)
        {
            int res = ar[j + 1][i] - ar[j - 1][i];
            int div = ar[j + i ][0] - ar[j - i][0];
            ar[j][i + 1] = res / div;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        cout << "f" << i << "(x)\t";
    }
    cout << endl;
    print();
    int x;
    cout << "Enter the value of x : ";
    cin >> x;
    int sum = ar[0][1];
    for (int i = 2; i < n; i++)
    {
        int mul = ar[i - 1][i];
        for (int j = 0; j < 2 * (i - 1); j += 2)
        {
            mul *= (x - ar[j][0]);
        }
        sum += mul;
    }
    cout << "\nf(" << x << ") = " << sum << endl;

    return 0;
}

/*
input:

5
5 150
7 392
11 1452
13 2366
21 9702
6


*/

