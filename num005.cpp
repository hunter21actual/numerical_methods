// Integration using Simpson's three eight rule
// Works well when no. of sub intervals are multiples of 3

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

double simpson_three_eight(double y[], int n, double h)
{
    double I1 = 0;
    for(int i = 1; i < n; ++i){
        if(i%3)
            I1 += 3*y[i];
    }

    double I2 = 0;
    for(int i = 3; i < n; i += 3)
        I2 += 2*y[i];

    double ans = I1 + I2;
    ans += y[0] + y[n];
    ans *= (3*h/8);
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

    double integral = simpson_three_eight(y,n,h);
    printf("\nThe value of the integral is = %.4lf", integral);
    return 0;
}
