// Initial value problem using 4th order Runge Kutta Method
// For 2 variables x and y
// Max no. of iterations = 10
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double y[11];

// Differential equation definition
double f(double x, double y)
{
    return y - x;
}

int main()
{
    int n;              // No. of iterations
    double x0, y0, h, pt;
    printf("Enter n: ");
    scanf("%d", &n);
    int it = n;
    printf("Initial value of x: ");
    scanf("%lf", &x0);
    printf("Initial value of y: ");
    scanf("%lf", &y0);
    y[0] = y0;
    printf("Point at which value is to be calculated: ");
    scanf("%lf", &pt);
    h = (pt - x0)/n;


    double k1, k2, k3, k4;
    int i = 0;
    while(n >= 0){
        k1 = h*f(x0, y[i]);
        k2 = h*f(x0 + (h/2.0), y[i] + (k1/2.0));
        k3 = h*f(x0 + (h/2.0), y[i] + (k2/2.0));
        k4 = h*f(x0 + h, y[i] + k3);
        y[i+1] = y[i] + (1/6.0)*(k1 + 2*(k2 + k3) + k4);
        x0 += h;
        n--;
        i++;
    }

    printf("Answer = %.4lf ", y[it]);
    return 0;
}
