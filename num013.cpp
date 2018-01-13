// Cube root of a number using Newton's formula
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

double x[20];

// Cube root function
double f(int x, int N)
{
    return x*x*x - N;
}

bool errorCheck(double x1, double x2)
{
    if(abs(x2 - x1) < 0.0001)
        return true;
    else
        return false;
}

int main()
{
    int N;
    scanf("%d", &N);
    int x0 = 0;
    int x1 = 0;

    // To find interval in which root lies
    while(f(x0,N)*f(x1,N) > 0){
        x0 = x1;
        x1++;
    }

    x[0] = x0;
    x[1] = x1;

    int index = 0;
    for(int i = 0; i < 15; ++i){
        x[i+1] = (2*pow(x[i], 3) + N) / (3*pow(x[i], 2));
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
