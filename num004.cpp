// Integration using Simpson's one third rule
// Works well only for even no. of sub intervals

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double y[101];

// Define the function here
double f(double x)
{
    return 1/(1 + x*x);
}

double simpson_one_third(double y[], int n, double h)
{
    double I1 = 0;
    for(int i = 1; i < n; i += 2)
        I1 += 4*y[i];

    double I2 = 0;
    for(int i = 2; i < n; i += 2)
        I2 += 2*y[i];

    double ans = I1 + I2;
    ans += y[0] + y[n];
    ans *= (h/3);
    return ans;
}

int main()
{
    double a, b;
    int n;
    printf("Enter the lower limit, upper limit and no.of sub intervals seperated by spaces.\n");
    scanf("%lf %lf %d", &a, &b, &n);

    double h = (b - a)/n;

    double j = a;
    for(int i = 0; i <= n; i++){
        y[i] = f(j);
        j += h;
    }
    
    //Uncomment to view function values
    /*for(int i = 0; i <= n; ++i)
        printf("%lf\n", y[i]);*/

    double integral = simpson_one_third(y,n,h);
    printf("\nThe value of the integral is = %.4lf", integral);
    return 0;
}
