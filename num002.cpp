// Code for Thomas algorithm to solve simultaneous linear equations AX = B
// Works best for tridiagonal matrices
// Numerically unstable for general cases
// Complexity = O(N) 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double gamm[10];
double beta[10];
double eqn[10][11];
double table[10][3];
double ans[11];

int main()
{
    int n;          // No. of equations
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= n; ++j)
            scanf("%lf", &eqn[i][j]);
    }

    // Create the coefficient table
    table[0][0] = 0;
    int x = 1, y = 0;
    for(int i = 1; i < n; ++i){
        table[i][0] = eqn[x][y];
        x++;
        y++;
    }

    for(int i = 0; i < n; ++i)
        table[i][1] = eqn[i][i];

    x = 0; y = 1;
    for(int i = 0; i < n - 1; ++i){
        table[i][2] = eqn[x][y];
        x++;
        y++;
    }
    table[n-1][2] = 0;

    // Calculating diagonal values
    for(int i = 1; i < n; ++i)
        gamm[i] = table[i-1][2]/(table[i-1][1] - table[i-1][0]*gamm[i-1]);

    // Calculating new values
    for(int i = 1; i <= n; ++i)
        beta[i] = (eqn[i-1][n] - table[i-1][0]*beta[i-1])/(table[i-1][1] - table[i-1][0]*gamm[i-1]);


    // Uncomment to print difference table
    /*for(int i = 0; i < n; ++i){
        for(int j = 0; j <= n; ++j)
            printf("%.3lf\t", eqn[i][j]);
        printf("\n");
    }

    printf("\n\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 3; ++j)
            printf("%.3lf\t", table[i][j]);
        printf("\n");
    }

    printf("\n\n");
    for(int i = 1; i < n; ++i)
        printf("%.3lf\t", gamm[i]);

    printf("\n\n");
    for(int i = 1; i <= n; ++i)
        printf("%.3lf\t", beta[i]);*/

    // Backward substitution
    ans[n] = beta[n];
    for(int i = n - 1; i > 0; i--)
        ans[i] = beta[i] - gamm[i]*ans[i+1];

    printf("\n");
    for(int i = 1; i <= n; ++i)
        printf("x%d = %.3lf\n", i, ans[i]);

    return 0;
}
