#include<bits/stdc++.h>
using namespace std;

int main()

{

    float ar[20][20],x[20],e,big,temp,relerror,sum;

    int n,i,j,maxit,itr;

    char ch;

    printf("\n\nENTER THE SIZE OF THE EQUATION :: ");

    cin>>n;

    for(i=1;i<=n;i++)

    {

        printf("\n\nEnter the coefficints of  equation %d and RHS \n",i);

        for(j=1;j<=n+1;j++)

        cin>>ar[i][j];

    }
    printf("\n\nEnter relative error and number of iteration ::  \n");

    cin>>e>>maxit;

    for(i=1;i<=n;i++)

    x[i]=0;

    for(int k=1;k<=maxit;k++)

    {

        big=0;

        for(i=1;i<=n;i++)

        {

            sum=0;

            for(j=1;j<=n;j++)

             {

               if(i!=j)

                  sum=sum+ar[i][j]*x[j];

              }

            temp=(ar[i][n+1]-sum)/ar[i][i];

            relerror=fabs((x[i]-temp)/temp);

            if(relerror>big)

               big=relerror;

            x[i]=temp;

        }

    if(big<=e)

    {

        printf("Converges to a solution in %d iterations\n",itr);

        for(i=1;i<=n;i++)

        printf("\n%.4f\t",x[i]);

       // getch();

        exit(1);

    }

     }

  printf("does not converge in %d iteration \n",maxit);

 // getch();

  return 0;

 }

