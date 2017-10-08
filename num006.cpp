// Integration using Romberg's rule

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double I[10];

// Define the function here
double f(double x)
{
    return 1/(1 + x*x);
}

// Integration using trapezoidal rule
double trap(double a, double b, int n)
{
    double y[64] = {0.0};
    double h = (b - a)/n;

    double j = a;
    for(int i = 0; i <= n; i++){
        y[i] = f(j);
        j += h;
    }

    double ans = 0;
    for(int i = 1; i < n; ++i)
        ans += 2*y[i];
    ans += y[0] + y[n];
    ans *= (h/2);
    return ans;
}

// Error check function
bool e(double I1, double I2)
{
    if(abs(I1 - I2) < 0.0001)
        return true;
    else
        return false;
}

/* function to calculate
I = I[k] - ((I[k] - I[k-1])/3) */
double R(double X, double Y)
{
    return Y + ((Y - X)/3.0);
}

int main()
{
    double a, b;
    printf("Enter the lower limit and upper limit seperated by spaces.\n");
    scanf("%lf %lf", &a, &b);

    I[1] = trap(a,b,2);
    I[2] = trap(a,b,4);
    I[3] = trap(a,b,8);

    int k = 1;
    int p = 8;
    while(!e(R(I[k], I[k+1]), R(I[k+1], I[k+2]))){
        p *= 2;
        I[k+3] = trap(a,b,p);
        k++;
    }

    double romberg = R(I[k+1], I[k+2]);
    printf("\nThe value of the integral is = %.4lf", romberg);
    return 0;
}
