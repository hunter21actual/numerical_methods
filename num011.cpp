// Finding root using Newton's formula
// Fails if at any point x, f'(x) i.e. derivative of f at x equals 0

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

// Definition of the function whose root we need to calculate
double f(double x)
{
    return x*x*x - 2*x - 0.5;
}

// Derivative of the function
double fx(double x)
{
    return 3*x*x - 2;
}

double x[20];

bool errorCheck(double x1, double x2)
{
    if(abs(x2 - x1) < 0.0001)
        return true;
    else
        return false;
}

int main()
{
    int x0 = 0;
    int x1 = 0;

    // To find interval in which root lies
    while(f(x0)*f(x1) > 0){
        x0 = x1;
        x1++;
    }

    x[0] = x0;
    x[1] = x1;

    int index = 0;
    for(int i = 0; i < 15; ++i){
        x[i+1] = x[i] - (f(x[i]) / fx(x[i]));
        index++;
        if(errorCheck(x[i], x[i-1]))
            break;
    }

    // Uncomment to view iteration table
    /*for(int i = 0; i < 10; ++i)
      printf("%.4lf\n", x[i]);*/
    printf("Found root at x = %.4lf\n", x[index]);
    return 0;
}
