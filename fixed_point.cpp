#include<stdio.h>
#include<math.h>
#define eps 0.0001

int coef[10] , i , j , n;

double G(double x)
{
    double a = 0;
    if(coef[1]!=0){
        for(i=n;i>=0;i--)
        {
            if(i!=1) a = a + (-coef[i]*pow(x,i));
        }
        a = a / coef[1];
    }

    else{
        for(i=n;i>=0;i--)
        {
            if(i!=1 && i!=n) a = a +((-coef[i]*pow(x,i))/pow(x,n-1));
        }

    }

    return a;
}

int main ()
{
    double x1 , x0 ;
    int maxItr;

    printf("Enter the maximun power : ");
    scanf("%d",&n);

    printf("Enter the Coefficients : ");

    for(i=n;i>=0;i--)
        scanf("%d",&coef[i]);


    printf("Enter initial estimate of a root : ");
    scanf("%lf",&x0);

    for(j=1 ;j<= 0; j++)
    {
        x1 = G(x0);
        if(fabs(x1-x0)<eps)
            break ;

        printf("\nAfter %d iteration x1 : %lf\n", j , x1);
        x0 = x1 ;
    }
    printf("\nThe root is : %lf",x1);
    return 0;

}



