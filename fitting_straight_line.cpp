#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"\t--------Fitting a Straight line--------"<<endl;

    int n;

    cout<<"\tEnter how many values you want for(x,y) : ";
    cin>>n;

    float x[n+1], y[n+1], xx[n+1], xy[n+1];

    cout<<"\tEnter the values for x : ";
    for(int i=0; i<n; i++)
        cin>>x[i];

    cout<<"\tEnter the values for y : ";
    for(int i=0; i<n; i++)
        cin>>y[i];


    cout<<endl<<"\t-----------------------------------------"<<endl;
    cout<<"\txi \t yi \t xi*xi \t xi*yi"<<endl;
    cout<<"\t-----------------------------------------"<<endl;

    for(int i=0; i<n; i++){
        xx[i] = x[i]*x[i];
        xy[i] = x[i]*y[i];
        cout<< "\t" << x[i] << "\t" << y[i] << "\t" << xx[i] << "\t" << xy[i] << endl;
    }

    x[n]=0;
    y[n]=0;
    xx[n]=0;
    xy[n]=0;


    for(int i=0; i<n; i++){
        x[n] += x[i];
        y[n] += y[i];
        xx[n] += xx[i];
        xy[n] += xy[i];
    }
    cout<<endl<<"sum = \t" << x[n] << "\t" << y[n] << "\t" << xx[n] << "\t" << xy[n] << endl <<endl;


    float a, b;

    b = (n*xy[n] - x[n]*y[n]) / (n*xx[n] - x[n]*x[n]);
    a = y[n]/n - b*(x[n]/n);

    cout<<"\tThe equation is y = " << a << " + " << b <<" x"<<endl;

    return 0;
}
