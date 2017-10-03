// Integration using trapezoidal rule

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double y[101];

// Define the function here
double f(double x)
{
    return 1/(1 + x);
}

double trap(double y[], int n, double h)
{
    double ans = 0;
    for(int i = 1; i < n; ++i)
        ans += 2*y[i];
    ans += y[0] + y[n];
    ans *= (h/2);
    return ans;
}

int main()
{
    double a, b;
    int n;
    printf("Enter the lower limit, upper limit and no.of intervals seperated by spaces.\n");
    scanf("%lf %lf %d", &a, &b, &n);

    double h = (b - a)/n;

    double j = a;
    for(int i = 0; i <= n; i++){
        y[i] = f(j);
        j += h;
    }
    
    // Uncomment for viewing function values 
    /*for(int i = 0; i <= n; ++i)
        printf("%lf\n", y[i]);*/

    double integral = trap(y,n,h);
    printf("\nThe value of the integral is = %.4lf", integral);
    return 0;
}
