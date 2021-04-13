
#include <bits/stdc++.h>
using namespace std;
#define Max 100

using namespace std;

int main()
{
    double x[Max],fx[Max],sum = 0.0 , xp,lf;
    int n;
    printf("Enter the number of set : ");
    cin>>n;
    printf("Enter Data point and the function value of that point : \n\n");
    for(int i = 0 ; i < n ;i++)
    {
        //printf("x[%d] = ",i);
        cout<<"x = "<<i;
        cin>>x[i];
        //printf("fx[%d] = ",i);
         cout<<"fx = "<<i;
         cin>>fx[i];
        //scanf("%lf",&fx[i]);
    }
    printf("Enter the value at which interpolation is required : ");
    cin>>xp;
    //scanf("%lf",&xp);
    for(int i = 0 ; i < n ; i++)
    {
        lf = 1.0;
        for(int j = 0 ; j < n ;j++)
        {
            if(i != j)
            {
                lf *= (xp-x[j])/(x[i]-x[j]);
            }
        }
        sum += lf*fx[i];
    }
    printf("Interpolated function value \n\n ");
    printf("at x = %lf is %0.4lf\n",xp,sum);
    return 0;
}
