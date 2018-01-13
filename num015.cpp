//Simultaneous equations using Newton Raphson method
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

double x[10];
double y[10];
double D[2][2];
double D1[2][2];
double D2[2][2];

// Function definitions
// f denotes f(x) g denotes g(x)
// fx denotes 1st derivative w.r.t x
// fy denotes 1st derivative w.r.t y and so on...
double f(double x, double y)
{
    return 2*x*x - 4*x*y - y*y;
}

double g(double x, double y)
{
    return 2*y*y + 10*x - x*x - 4*x*y - 5;
}

double fx(double x, double y)
{
    return 4*x - 4*y;
}

double fy(double x, double y)
{
    return -4*x - 2*y;
}

double gx(double x, double y)
{
    return 10 - 2*x - 4*y;
}

double gy(double x, double y)
{
    return 4*y - 4*x;
}

double det(double A[][2])
{
    return A[0][0]*A[1][1] - A[0][1]*A[1][0];
}


int main()
{
    // initial values of x and y
    x[0] = 1.0, y[0] = 1.0;

    double h, k;

    // n denotes no. of iterations
    int i = 0, n = 4;
    //printf("x[%d] = %.4lf\ty[%d] = %.4lf\n", i, x[i], i, y[i]);

    // Uncomment inside while loop to see function values at each iteration
    while(n){
        /*printf("f(x, y) = %.4lf\n", f(x[i], y[i]));
        printf("g(x, y) = %.4lf\n", g(x[i], y[i]));
        printf("fx(x, y) = %.4lf\n", fx(x[i], y[i]));
        printf("gx(x, y) = %.4lf\n", gx(x[i], y[i]));
        printf("fy(x, y) = %.4lf\n", fy(x[i], y[i]));
        printf("gy(x, y) = %.4lf\n\n", gy(x[i], y[i]));*/
        D[0][0] = fx(x[i], y[i]);
        D[0][1] = fy(x[i], y[i]);
        D[1][0] = gx(x[i], y[i]);
        D[1][1] = gy(x[i], y[i]);

        D1[0][0] = f(x[i], y[i]);
        D1[0][1] = fy(x[i], y[i]);
        D1[1][0] = g(x[i], y[i]);
        D1[1][1] = gy(x[i], y[i]);

        D2[0][0] = fx(x[i], y[i]);
        D2[0][1] = f(x[i], y[i]);
        D2[1][0] = gx(x[i], y[i]);
        D2[1][1] = g(x[i], y[i]);

        h = -det(D1)/det(D);
        k = -det(D2)/det(D);

        //printf("h = %.4lf\tk = %.4lf\n", h, k);

        x[i+1] = x[i] + h;
        y[i+1] = y[i] + k;

        //printf("x[%d] = %.4lf\ty[%d] = %.4lf\n\n\n", i+1, x[i+1], i+1, y[i+1]);

        i++;
        n--;
    }

    printf("x, y = %.4lf, %.4lf\n", x[i], y[i]);

    return 0;
}
