// Integration using Gauss's quadrature 2 point formula

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

// Function definition
double f(double x)
{
    return 1/(1 + x*x*x);
}

// Transform to integral w/ lower limit -1 and upper limit +1
double tf(double a, double b, double t)
{
    return ((b - a) / 2.0)*f(((a + b) / 2.0) + ((b - a) / 2.0)*t);
}


int main()
{
    double a, b;
    printf("Enter the lower limit and upper limit seperated by spaces.\n");
    scanf("%lf %lf", &a, &b);

    double pt = 1/sqrt(3);
    double gauss_two_point = tf(a, b, pt) + tf(a, b, -pt);

    printf("\nThe value of the integral is = %.4lf", gauss_two_point);
    return 0;
}
