//Code for Newton's forward interpolation

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double x[10];
double y[10];

double table[10][10] = {{0}};

double c(double n, int k)
{
    double coeff = 1.0;
    for(int i = 0; i < k; ++i){
        coeff *= (n - i)/(i+1);
    }
    return coeff;
}

int main()
{
    int n;          // No. of points
    double x0;      // point at which value is to be calculated
    scanf("%d %lf", &n, &x0);

    for(int i = 0; i < n; ++i)
        scanf("%lf %lf", &x[i], &y[i]);

    // Create the difference table
    for(int i = 0; i < n; ++i)
        table[i][0] = y[i];

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n - i; ++j)
            table[j][i] = table[j+1][i-1] - table[j][i-1];
    }

    // Uncomment to print difference table
    /*for(int i = 0; i < n; ++i){
        for(int j = 0; j < n - i; ++j)
            printf("%.3lf\t", table[i][j]);
        printf("\n");
    }*/

    double h = x[1] - x[0];

    double ccp = x0;                 // Subinterval length
    int index = 0;
    while(x0 - x[index] > 0){
        ccp = x[index];               // Starting point
        index++;
    }

    double N = (x0 - ccp)/h;

    // Newton's forward difference formula
    double ans = 0;
    for(int i = 0; i < n; ++i){
        ans += (table[index-1][i]*c(N,i));
    }

    printf("\n%.4lf", ans);

    return 0;
}
